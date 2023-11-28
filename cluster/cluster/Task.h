#pragma once


class task {

public:
	/** @param taktsLimit ������ ��������� ������.
		@param nodesLimit ������ ��������� �����. */
	task(int taktsLimit, int nodesLimit);

	/* ��������� true, ���� ������ ���������� ���� � false, ���� ������ ��������� ���� ������. */
	bool runTa�t();
	/* ��������� ���������� ������������ ������� �����. */
	int getNodes() const;
	/* ��������� ���������� ������������ ������� ������. */
	int getTa�ts() const;
	/* ��������� ����� ������. */
	int getId() const;

private:
	int ta�ts, nodes;
	static int nextId; // ����������� ���������� ��� �������� ���������� id.
	int id; // ���������� ��� �������� id �������� �������.
};