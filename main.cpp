//Data

//68 43 10 56 77 82 61 33 72 66 99 88 12 6 7 21 -999

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	string fileName;
	string info;
	cout << "Enter the input file name ";
	cin  >> fileName;
	ifstream inData;
	ofstream outData;
	inData.open(fileName.c_str());
	outData.open("out.txt");
	inData>>info;
	BSearchTreeType<int>  treeRoot, otherTreeRoot;
	
	int num;

	//Enter numbers ending with -999";
	inData >> num;

	while (num != -999)
	{
		treeRoot.insert(num);
		inData >> num;
	}

	cout << endl << "Tree nodes in inorder: ";
	treeRoot.inorderTraversal();

	cout << endl << "Tree nodes in preorder: ";
	treeRoot.preorderTraversal();

	cout << endl << "Tree nodes in postorder: ";
	treeRoot.postorderTraversal();
	cout << endl;

	cout    << "Tree Height: " << treeRoot.treeHeight() << endl;
	outData << "Tree Height: " << treeRoot.treeHeight() << "\n";

	cout    << "Number of Nodes: " << treeRoot.treeNodeCount() << endl;
	outData << "Number of Nodes: " << treeRoot.treeNodeCount() << "\n";

	cout    << "Number of Leaves: " << treeRoot.treeLeavesCount() << endl;
	outData << "Number of Leaves: " << treeRoot.treeLeavesCount() << "\n";

	cout    << "Number of Single Parents: " << treeRoot.singleParent() << endl;
	outData << "Number of Single Parents: " << treeRoot.singleParent() << "\n";

	inData.close();
	outData.close();

	return 0;
}
