#pragma once
class Counter
{
private:
	unsigned int count;
public:
	Counter() : count(0) {}
	void add() { count++; }
	void add(int n) { count += n; }
	int show() { return count; }
	void clear() { count = 0; }
};

