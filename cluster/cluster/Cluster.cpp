#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "Interface.h"
#include <windows.h>
#include "Cluster.h"
#include "Console.h"
#include "Queue.h"
#include <conio.h>
#include "Task.h"

using namespace std;


cluster::cluster(
	int availableNodes,
	unsigned int tactTime,
	unsigned int tasksPerTact,
	unsigned int taskTaktsLimit,
	double taskAppearLimit) :
	ta�tTime(tactTime),
	tasksPerTa�t(tasksPerTact),
	taskTa�tsLimit(taskTaktsLimit) {

	if (availableNodes < 16 || availableNodes > 64) { throw runtime_error("Invalid count of nodes"); }

	this->availableNodes = availableNodes;
	initialNodes = availableNodes;

	if (taskAppearLimit <= 0 || taskAppearLimit >= 1.0) { throw runtime_error("Invalid taskAppearLimit"); }

	this->taskAppearLimit = taskAppearLimit;
}

void cluster::runCluster() {

	random_device rd;
	mt19937 gen(rd());

	cluster_interface newInterface;
	TStackQueue<task> queue;
	vector<task> runningTasks;
	vector<task> tasks;
	
	double taskProbability = 0.0;
	double loadPercentage = 0.0;
	int ta�tsCount = 0;
	int complCount = 0;
	int labelsCount = 1;
	int newTasksCount = 0;
	int runtimeTa�tsCount = 0;

	gotoxy(30, 22);
	cout << "��� ������ �������: q/Q.";
	newInterface.drawField();
	newInterface.label("----------------------------------------", 3, 4);
	newInterface.label("----------------------------------------------", 44, 4);
	newInterface.label("�����������:", 65, 3);
	newInterface.label("\t\t����� ������:", 5, 5);
	
	while (true)
	{
		if (_kbhit()) 
		{
			char ch = _getch();
			if (ch == 'q' || ch == 'Q') { break; }
		}

		newInterface.label("\t\t������� ����: �" + to_string(ta�tsCount), 5, 3);
		tasks.clear();

		for (int i = 1; i <= newTasksCount; i++) { newInterface.label("                    ", 5, 6 + i); }

		for (int i = 1; i <= labelsCount; i++)
		{
			newInterface.label("                                     ", 5, 7 + tasksPerTa�t + i);
		}

		for (int i = 0; i < runtimeTa�tsCount; i++)
		{
			newInterface.label("                                     ", 50, 5 + i);
		}

		for (int i = 0; i < tasksPerTa�t; i++)
		{
			if (uniform_real_distribution<double>{0.1, 0.9}(gen) <= taskAppearLimit)
			{
				task newTask(taskTa�tsLimit, initialNodes);
				
				tasks.push_back(newTask);
				newInterface.label("������ �" + to_string(newTask.getId()) + " [" + to_string(newTask.getTa�ts()) + ", " + to_string(newTask.getNodes()) + "]", 5, 6 + tasks.size());
			}
		}
		newInterface.label("----------------------------------------", 3, 7 + tasksPerTa�t);
		newTasksCount = tasks.size();
		labelsCount = 1;
		
		for (int i = 0; i < tasks.size(); i++)
		{
			if (tasks[i].getNodes() <= availableNodes && queue.isEmpty())
			{
				availableNodes -= tasks[i].getNodes();
				runningTasks.push_back(tasks[i]);

				textcolor(LIGHTGREEN);
				newInterface.label("������ �" + to_string(tasks[i].getId()) + " ����������� �� ����������.", 5, 7 + tasksPerTa�t + labelsCount);
				textcolor(WHITE);
				labelsCount++;
			}
			else
			{
				queue.push(tasks[i]);
				textcolor(BLUE);
				newInterface.label("������ �" + to_string(tasks[i].getId()) + " ������������ � �������.", 5, 7 + tasksPerTa�t + labelsCount);
				textcolor(WHITE);
				labelsCount++;
			}
		}
		runtimeTa�tsCount = 0;
		for (int i = 0; i < runningTasks.size(); i++)
		{
			if (runningTasks[i].runTa�t())
			{
				newInterface.drawProcess(runningTasks[i], 50, 5 + i);
				runtimeTa�tsCount++;
				continue;
			}

			textcolor(YELLOW);
			newInterface.label("������ �" + to_string(runningTasks[i].getId()) + " ���������!", 5, 7 + tasksPerTa�t + labelsCount);
			textcolor(WHITE);
				
			complCount++;
			labelsCount++;
			runtimeTa�tsCount++;

			availableNodes += runningTasks[i].getNodes();
			runningTasks.erase(runningTasks.begin() + i);
			i--;

			if (!queue.isEmpty())
			{
				for (int j = 0; j < queue.size(); j++)
				{
					if (queue.top().getNodes() <= availableNodes)
					{
						runningTasks.push_back(queue.pop());
						availableNodes -= runningTasks.back().getNodes();		

						textcolor(LIGHTGREEN);
						newInterface.label("������ �" + to_string(runningTasks.back().getId()) + " ����������� �� ����������.", 5, 7 + tasksPerTa�t + labelsCount);
						textcolor(WHITE);

						labelsCount++;
						j--;
					}
					else { break; }
				}
			}	
		}
		ta�tsCount++;
		loadPercentage += static_cast<double>(initialNodes - availableNodes) / initialNodes;
		Sleep(ta�tTime);
	}
	clrscr();
	cout << "\n~~~~~~~~~~����������~~~~~~~~~~\n";
	cout << "������ ����������: " << ta�tsCount << endl;
	cout << "����� ���������: " << complCount << endl;
	cout << "����� �� ���������: " << queue.size() + runningTasks.size() << endl;
	cout << "�����  �����: " << queue.size() + runningTasks.size() + complCount << endl;
	cout << "������� �������� ��������: " << static_cast<int>(round(loadPercentage / ta�tsCount * 100)) << "%\n\n" << endl;
}
