#pragma once
#include "Task.h"
#include <string>

using namespace std;


class cluster_interface {

public:
	cluster_interface();
	/** @param label ������� ��� ������.
		@param x ���������� x.
		@param y ���������� y. */
	void label(string label, int x, int y);
	/** @param newTask ����������� ������.
		@param x ���������� x.
		@param y ���������� y. */
	void drawProcess(task newTask, int x, int y);
	/* ��������� ����. */
	void drawField();
};