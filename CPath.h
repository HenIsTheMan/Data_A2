#pragma once
#include <iostream>
#include "CNode.h"
using namespace std;

class CPath{
	public:
		CPath(), ~CPath();
		void addNode(), deleteNode(), engageUser(), start();
		void print() const;
	private:
		CNode *head, *in;
};