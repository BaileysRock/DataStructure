#include"Huffman.h"

int main()
{
	//������ĸ��ѹ��������
	string HuffmanEncoding[128];
	CharSetHuffmanEncoding(HuffmanEncoding);
	Convert_Output_file_list(HuffmanEncoding);
	Convert_Output_file("Huffman_Compress_List.txt", "Huffman_Compress.txt");
	Recover_from_file(HuffmanEncoding);
	Compress_percent("Huffman_Compress.txt");

	//���ڵ��ʵ�ѹ��������
	//���ö��Ż�������������
	Optimize_Huffman huffman_optimize[Max_length];
	WordSetHuffmanWeight(huffman_optimize);
	int n = Count_huffman(huffman_optimize);
	WordSetHuffmanTree(huffman_optimize);
	Compress_Optimize_file_list(huffman_optimize);
	Convert_Output_file("Huffman_Compress_List_Optimize.txt", "Huffman_Compress_Optimize.txt");
	Recover_from_file_optimize(huffman_optimize, n);
	Compress_percent("Huffman_Compress_Optimize.txt");
	return 0;

}