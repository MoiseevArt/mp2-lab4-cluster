#pragma once

using namespace std;


class cluster {

public:
	/** @param availableNodes ���������� ����� ��������.
		@param taktTime ����������������� ����� � ��. 
		@param tasksPerTakt ���������� ����� �� ����, ������� ����� ���������. 
		@param taskTaktsLimit ������ ��������� ������ �����. 
		@param taskAppearLimit ����������� ��������� ������. 
		*/
	cluster(
		int availableNodes,
		unsigned int ta�tTime,
		unsigned int tasksPerTa�t,
		unsigned int taskTa�tsLimit,
		double taskAppearLimit);

	cluster() = default;
	/* ������ �������� ������ ��������. */
	void runCluster();

private:
	int availableNodes = 48;      // ��������� ���������� �����
	int initialNodes = 48;        // �������� ���������� ����� (������)
	unsigned int ta�tTime = 10000; // ����������������� �����
	unsigned int tasksPerTa�t = 1; // ���������� ����� � ������ �����
	unsigned int taskTa�tsLimit = 5; // ����� ������ �� ���������� ������
	double taskAppearLimit = 0.3;   // ������ ��������� �����
};