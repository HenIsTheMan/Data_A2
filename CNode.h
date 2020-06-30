#pragma once

class CNode{
	public:
		CNode();
		char getCh() const;
		CNode *getPrev() const, *getNext() const;
		void setCh(char), setPrev(CNode*), setNext(CNode*);
	private:
		char ch;
		CNode *prev, *next;
};