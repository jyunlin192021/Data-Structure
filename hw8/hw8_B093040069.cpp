//製作 Huffman 壓縮軟體
#include <iostream> 
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std; 
#define MAX_TREE_HT 100 //max tree height

// A Huffman tree node 
struct MinHeapNode { 
    char data; // One of the input characters 
    unsigned freq; // Frequency of the character 
    struct MinHeapNode *left, *right; // Left and right child of this node 
};  
// A Min Heap: Collection of min-heap (or Huffman tree) nodes 
struct MinHeap { 
    unsigned size; // Current size of min heap 
    unsigned capacity; // capacity of min heap 
    struct MinHeapNode** array; // Array of minheap node pointers 
};
// Input error
int othercase() {
	cout << "  compress EX: huffman -c infile -o outfile\n"
		<< "uncompress EX: huffman -u infile -o outfile\n";
	return 1;
}
// Get file size
int getFileSize(string& sFileName) {
	struct stat buf;
	int iRet = stat(sFileName.c_str(), &buf);
	if (iRet == -1)
		return 0;
	return buf.st_size;
}
// Check if size of heap is 1 or not 
int isSizeOne(struct MinHeap* minHeap) {
	return (minHeap->size == 1);
}
// Check if this node is leaf 
int isLeaf(struct MinHeapNode* root) {
	return !(root->left) && !(root->right);
}
// A new min heap node with given character and frequency of the character 
struct MinHeapNode* newNode(char data, unsigned freq) {
	struct MinHeapNode* temp
		= (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}
// Create a min heap of given capacity 
struct MinHeap* createMinHeap(unsigned capacity) {
	struct MinHeap* minHeap
		= (struct MinHeap*)malloc(sizeof(struct MinHeap));

	minHeap->size = 0; // current size is 0 
	minHeap->capacity = capacity;
	minHeap->array
		= (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

	return minHeap;
}
// Swap two min heap nodes 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}
// The standard minHeapify function. 
void minHeapify(struct MinHeap* minHeap, int idx) {
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;
	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}
// Extract minimum value node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}
// Insert a new node to Min Heap 
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}
// A standard function to build min heap 
void buildMinHeap(struct MinHeap* minHeap) {
	int n = minHeap->size - 1;
	for (int i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}
// Creates a min heap of capacity equal to size and inserts data[] in min heap.
// Initially size of min heap is equal to capacity 
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}
// The main function that builds Huffman tree 
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
	struct MinHeapNode* left, * right, * top;

	// Step 1: Create a min heap of capacity equal to size.
	// Initially, there are modes equal to size. 
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	// Iterate while size of heap doesn't become 1 
	while (!isSizeOne(minHeap)) {
		// Step 2: Extract the two minimum freq items from min heap 
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		// Step 3: Create a new internal node with frequency equal to the 
		// sum of the two nodes frequencies. 
		// Make the two extracted node as left and right children of this new node. 
		// Add this node to the min heap 
		// '$' is a special value for internal nodes, not used 
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top);
	}
	// Step 4: The remaining node is the 
	// root node and the tree is complete. 
	return extractMin(minHeap);
}
// Set huffman codes from the root of Huffman Tree. 
// It uses arr[] to store codes 
void setCodes(struct MinHeapNode* root, int arr[], int top, ofstream& fout) {
	// Assign 0 to left edge and recur 
	if (root->left) {
		arr[top] = 0;
		setCodes(root->left, arr, top + 1, fout);
	}
	// Assign 1 to right edge and recur 
	if (root->right) {
		arr[top] = 1;
		setCodes(root->right, arr, top + 1, fout);
	}
	// If this is a leaf node, then it contains one of the input 
	// characters, set the character and its code from arr[] 
	if (isLeaf(root)) {
		fout << (int)(root->data) << "=";
		for (int i = 0; i < top; i++)
			fout << arr[i];
		fout << endl;
	}
}
// Builds a Huffman Tree and set codes by traversing the built Huffman Tree 
void HuffmanCodes(char data[], int freq[], int size, ofstream& fout) {
	// Construct Huffman Tree 
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	// Set Huffman codes using the Huffman tree built above 
	int arr[MAX_TREE_HT], top = 0;
	setCodes(root, arr, top, fout);
	fout << "***\n";
}
// Encode 2
void Encode2(char* infile, char* outfile) {
	ifstream fin;
	ofstream fout;
	fin.open(outfile, ios::in); // read table

	int i, j, num;
	char ch;
	vector<char> chV;
	string ch_arr[256], str;
	for (i = 0; i < 256; i++) {
		ch_arr[i] = "";
	}
	while (fin >> str) {
		if (str == "***")
			break;
		int n = atoi(&str[0]);
		for (i = 0; i < str.length(); i++) {
			if (str[i] == '=')
				break;
		}
		ch_arr[n + 128] = &str[i + 1];
	}
	fin.close();
	fin.open(infile, ios::in | ios::binary);
	fout.open(outfile, ios::out | ios::binary); // encode
	while (!fin.eof()) {
		fin.get(ch);
		if (!fin.eof()) {
			str = ch_arr[(int)ch + 128];
			for (i = 0; i < str.length(); i++) {
				chV.push_back(str[i]);
				if (chV.size() == 8) {
					chV.clear();
				}
			}
		}
	}
	if (chV.size() > 0)
		fout << 8 - chV.size() << endl;
	else
		fout << 0 << endl;

	fin.close();
	fout.close();
}
// Build encoding table
void buildTable(char* infile, char* outfile) {
	ifstream fin;
	ofstream fout;

	int i;
	char ch; //for read
	int count[256] = { 0 }; //calculate the freq
	fin.open(infile, ios::in | ios::binary);
	while (!fin.eof()) {
		fin.get(ch);
		if (!fin.eof()) {
			count[(int)ch + 128]++;
		}
	}
	fin.close();
	vector<char> dataV; //data vector
	vector<int> freqV; //freq vector
	for (i = 0; i < 256; i++) {
		if (count[i] > 0) {
			dataV.push_back((char)(i - 128));
			freqV.push_back(count[i]);
		}
	}
	char* data = new char[dataV.size()];
	int* freq = new int[freqV.size()];
	for (i = 0; i < dataV.size(); i++) {
		data[i] = dataV[i];
		freq[i] = freqV[i];
	}
	fout.open(outfile, ios::out);
	HuffmanCodes(data, freq, dataV.size(), fout);
	fout.close();
	Encode2(infile, outfile);
	for (i = 0; i < dataV.size(); i++) {
		data[i] = dataV[i];
		freq[i] = freqV[i];
	}
	fout.open(outfile, ios::out | ios::app | ios::binary);
	HuffmanCodes(data, freq, dataV.size(), fout);
	fout.close();
}

// As byte
void Byte(vector<char>& chV, ofstream& fout) {
	int i, sum = 0;
	char ch;
	for (i = 0; i < 8; i++) {
		ch = chV[i];
		if (ch == '1') {
			sum += pow(2, 7 - i);
		}
	}
	chV.clear();
	if (sum > 127) { sum -= 256; }
	ch = (char)sum;
	fout << ch;
}
// Turn 1 byte(char) to binary
void turnBinary(string& str, char ch, int num) {
	int b[8] = { 0 }, n = ch, count = 0;
	stringstream ss;
	if (n < 0)
		n += 256;
	while (n > 0) {
		b[count] = n % 2;
		n /= 2;
		count++;
	}
	for (int i = 0; i < 8; i++) {
		if ((7 - i) >= num)
			ss << b[7 - i];
	}
	str += ss.str();
}
// Check table and write 
void checkAndWrite(ofstream& fout, string& str, const string ch_arr[]) {
	int i, j;
	char ch;
	for (i = 0; i < 256; i++) {
		if (ch_arr[i] == "-1") continue;
		for (j = 0; j < str.length(); j++) {
			if (ch_arr[i] == str.substr(0, j + 1)) {
				ch = (char)(i - 128);
				fout << ch;
				if (j + 1 == str.length()) {
					str = "";
					return;
				}
				else {
					str = (str.substr(j + 1, str.length() - (j + 1)));
					return;
				}
			}
		}
	}
}
// Show table
void showTable(char* file) {
	ifstream fin;
	fin.open(file, ios::in);
	string str;
	cout << "\n\n";
	fin >> str;
	int i;
	while (fin >> str) {
		if (str == "***")
			break;
		cout << setw(4) << atoi(&str[0]) << " = ";
		for (i = 0; i < str.length(); i++) {
			if (str[i] == '=')
				break;
		}
		cout << &str[i + 1] << endl;
	}
	fin.close();
	cout << endl;
}
// Encode
void Encode(char* infile, char* outfile) {
	ifstream fin;
	ofstream fout;
	fin.open(outfile, ios::in); // read table

	int i, j, num;
	char ch;
	vector<char> chV;
	string ch_arr[256], str;
	for (i = 0; i < 256; i++) {
		ch_arr[i] = "";
	}
	fin >> num;
	while (fin >> str) {
		if (str == "***")
			break;
		int n = atoi(&str[0]);
		for (i = 0; i < str.length(); i++) {
			if (str[i] == '=')
				break;
		}
		ch_arr[n + 128] = &str[i + 1];
	}
	fin.close();
	fin.open(infile, ios::in | ios::binary);
	fout.open(outfile, ios::out | ios::app | ios::binary); // encode
	while (!fin.eof()) {
		fin.get(ch);
		if (!fin.eof()) {
			str = ch_arr[(int)ch + 128];
			for (i = 0; i < str.length(); i++) {
				chV.push_back(str[i]);
				if (chV.size() == 8) {
					Byte(chV, fout);
				}
			}
		}
	}
	int size = chV.size();
	if (size > 0) {
		for (i = 0; i < 8 - size; i++) {
			chV.push_back('0');
		}
		Byte(chV, fout);
	}

	fin.close();
	fout.close();
}

// Decode
void Decode(char* infile, char* outfile) {
	ifstream fin;
	ofstream fout;
	fin.open(infile, ios::in | ios::binary);
	fout.open(outfile, ios::out | ios::binary);

	int i, j, num;
	char ch;
	vector<char> chV;
	stringstream ss;
	string ch_arr[256], str;
	for (i = 0; i < 256; i++) {
		ch_arr[i] = "-1";
	}
	fin >> num;
	while (fin >> str) {
		if (str == "***") {
			fin.ignore(100, '\n');
			break;
		}
		int n = atoi(&str[0]);
		for (i = 0; i < str.length(); i++) {
			if (str[i] == '=')
				break;
		}
		ch_arr[n + 128] = &str[i + 1];
	}
	//-c input.txt -o output
	//-u output -o output.txt
	//-c HDL2.png -o output2
	//-u output2 -o HHDD.png
	char c;
	str = "";
	while (!fin.eof()) {
		fin.get(ch);
		c = fin.peek();
		if (!fin.eof()) {
			//cout << "ch: " << (int)ch << endl;
			turnBinary(str, ch, 0);
			while (str.length() > 10)
				checkAndWrite(fout, str, ch_arr);
		}
	}
	//cout << "***ch: " << (int)ch << endl;
	turnBinary(str, ch, num);
	while (!str.empty())
		checkAndWrite(fout, str, ch_arr);

	fin.close();
	fout.close();
}
int main(int argc, char *argv[]) {
	if(argc != 5)
		return othercase();

	
	if(argv[3][0]=='-'&&argv[3][1]=='o') {
		if(argv[1][0]=='-'&&argv[1][1]=='c') { //Compress
			cout << "Compressing...";
			// Build table
			buildTable(argv[2], argv[4]);
			// Encode
			Encode(argv[2], argv[4]);
			showTable(argv[4]);
			string infile = argv[2], outfile = argv[4];
			cout << "uncompressed size: " << getFileSize(infile) << " bytes\n";
			cout << "  compressed size: " << getFileSize(outfile) << " bytes\n";
			cout << "compression ratio: " 
			<< (double)getFileSize(infile)/getFileSize(outfile) << " bytes\n";
		}
		else if(argv[1][0]=='-'&&argv[1][1]=='u') { //Uncompress
			cout << "Uncompressing...";
			// Decode
			Decode(argv[2], argv[4]);
			showTable(argv[2]);
			string infile = argv[2], outfile = argv[4];
			cout << "uncompressed size: " << getFileSize(outfile) << " bytes\n";
			cout << "  compressed size: " << getFileSize(infile) << " bytes\n";
			cout << "compression ratio: " 
			<< (double)getFileSize(outfile)/getFileSize(infile) << " bytes\n";
		}
		else
			return othercase();
	}
	else
		return othercase();

	return 0;
}
