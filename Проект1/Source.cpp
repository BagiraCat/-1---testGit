#include <iostream>
using namespace std;
#define SIZESMALL 11 //���-�� ��������� � ������ � �������
#define SIZEBIG 22 //������ ��������������� �������
//#define DEBUG 


//������������
#ifdef DEBUG
void printArray(char A[SIZESMALL][SIZESMALL], int sizeCol, int sizeRow, int IsReverseRow, int IsReverseCol, int startRow, int startCol)
//������� ������������ ��� �������
{
	int i;
	int j;

	for (j = startCol; -1 * IsReverseCol*j > sizeCol*IsReverseCol*-1; ) //���� �� ��������, ��������� *IsReverse*-1 ������ ���� � ����������� �� ���� �������� ������ � ����� ��� � ������
																		//���� ������ �������� �������: i<10 - ��������� -i>-10 (IsReverse �������� 1), ���� ������ �������� � �����: i>-1 (IsReverse �������� -1 � ��� ��������� �� -1 �������� +����)
	{
		for (i = startRow; -1 * IsReverseRow*i > sizeRow*IsReverseRow*-1; ) //���� �� �������
		{
			cout << A[j][i];
			i = i + 1 * IsReverseRow; //�����������, ���� ��������� �������
		}
		cout << "\n";
		j = j + 1 * IsReverseCol; //�����������, ���� ��������� �������
	}
	//cout << "\n";
}
#endif

void printArray1(char A[SIZEBIG][SIZEBIG],
	int sizeCol, //�� ���� ������� �� ��������
	int sizeRow) //�� ���� ������� �� ��������

{
	int i;
	int j;

	cout << "Result Array" << endl;
	for (j = 0; j < sizeCol; j++)
	{
		for (i = 0; i < sizeRow; i++) //���� �� �������
		{
			cout << A[j][i];
		}
		cout << "\n";
	}
	//cout << "\n";
}

//������� ��� ��������������� ������������
void FillArrayTrCh(
	char A[SIZESMALL][SIZESMALL], //������ � ������������� �� ���� (������ 1)
	int sizeCol, //������, �� ������� ������������ ������������ ���������� ������� (���� ���� ������, �� = 11, ���� ���� �����, �� = -1
	int sizeRow, //������, �� ������� ������������ �������������� ���������� ������� (���� ���� ������, �� = 11, ���� ���� �����, �� = -1
	int IsReverseRow, //������� ��������������� ����� ��������� �������: -1 - ��������������, 1 - �� ��������������
	int IsReverseCol, //������� ��������������� �������� ��������� �������: -1 - ��������������, 1 - �� ��������������
	int startRow, //������ �������� ���� �� ������: ���� ������� = 0 (�� �������������� ������), ���� � ����� = 10 (�������������� ������)
	int startCol, //������ �������� ���� �� ��������: ���� ������� = 0 (�� �������������� �������), ���� � ����� = 10 (�������������� �������)
	char B[SIZESMALL][SIZESMALL]) //������������ ����������� (������ 2, 3 ��� 4 � ������������ �� ���������� ����������
{
	int i;
	int j;
	int n = 0; //������ ������ ������� �
	int m = 0; //������ ������� ������� �

	for (j = startCol; -1 * IsReverseCol*j > sizeCol*IsReverseCol*-1; ) //���� �� ��������, ��������� *IsReverse*-1 ������ ���� � ����������� �� ���� �������� ������ � ����� ��� � ������
																		//���� ������ �������� �������: i<10 - ��������� -i>-10 (IsReverse �������� 1), ���� ������ �������� � �����: i>-1 (IsReverse �������� -1 � ��� ��������� �� -1 �������� +����)
	{
		for (i = startRow; -1 * IsReverseRow*i > sizeRow*IsReverseRow*-1; ) //���� �� �������
		{
			B[n][m] = A[j][i];
			i = i + 1 * IsReverseRow; //�����������, ���� ��������� �������
			m++;
		}
		//cout << "\n";
		m = 0;
		j = j + 1 * IsReverseCol; //�����������, ���� ��������� �������
		n++;
	}
	//cout << "\n";
}

//������� ���������� ��������������� ������� (������� ����� �������� �� ������)
void FillResultArray(char
	A[SIZESMALL][SIZESMALL], //������ ������� ����� �������� � �������������� ������
	int sizeCol, //�� ���� ������� �� ��������
	int sizeRow, //�� ���� ������� �� ��������
	char B[SIZEBIG][SIZEBIG], //�������������� ������
	int BstartRow, // ��������� � ����� ������ ���������
	int BstartCol) // ��������� � ������ ����� � ������ ���������
{
	int i;
	int j;

	for (j = BstartRow; j < sizeCol; j++)
	{
		for (i = BstartCol; i < sizeRow; i++) //���� �� �������
		{
			B[j][i] = A[j - BstartRow][i - BstartCol]; //��������� � ����� ������� ��������� ������
		}
	}
	//cout << "\n";
}


int FillArrayTriangle(char Array[SIZESMALL][SIZESMALL], int size) //���������� ������� ��������� � * � ���� �������������� ������������ �������� size�size ����� (������ 1)
{
	size = 10; //���������� ����� � �������, ���������� ������� 11�11 (�.�. ���� ���� � 0 �� 10)
	int i;
	int j;
	
	for (j = 0; j <= size; j++) //���� �� ��������
	{
		for (i = 0; i <= size; i++) //���� �� �������
		{
			if (i > size - j)
			{
				Array[j][i] = ' ';
			}
			if (i <= size - j)
			{
				Array[j][i] = '*';
			}
		}
		//
	}

	return 0;
}

int FillArrayRectangle(char Array[SIZESMALL][SIZESMALL], int size) //���������� ������� ��������� � * � ���� �������������� ������������ �������� size�size �����
{
	int i;
	int j;
	int k = 0;

	for (j = 0; j <= size; j++) //���� �� ��������
	{
		for (i = 0; i <= size; i++) //���� �� �������
		{

			Array[j][i] = '*';
		}
		k++;
	}

	return 0;
}

int main()
//������� ������: ������� ��� ������ - �����������(������ 1) � �������������, ��� ��������������� ������������ �� ������ 1 � ������ 2,3 ��� 4 ���������� ������� ��������������� ������������
//����� ������� ������ �� 4 ��������: ����� ������� / ������, ������ ������� / ������
//����� ������ (������������� ��� �����������), ���� ����� - �������������� �����������, ��������� ������ ������ �� 4� �������� ������
//�������� ������������ ������ ArrayBIG
{
	//setlocale(LC_ALL, "Russian");
	
	void printArray(char A[SIZESMALL][SIZESMALL], int sizeCol, int sizeRow, int IsReverseRow, int IsReverseCol, int startRow, int startCol);
	int FillArrayTriangle(char Array1[SIZESMALL][SIZESMALL], int size1);
	int FillArrayRectangle(char Array2[SIZESMALL][SIZESMALL], int size);
	void FillResultArray(char
		A[SIZESMALL][SIZESMALL],
		int sizeCol, //�� ���� ������� �� ��������
		int sizeRow, //�� ���� ������� �� ��������
					 //int startRow, //� ������ ����� ���� �� �������
					 //int startCol, //� ������ ����� ���� �� ��������
		char B[SIZEBIG][SIZEBIG],
		int BstartRow, // � ����� ���� ���������
		int BstartCol); // � ������ ����� � ������ ���������

	void printArray1(char A[SIZEBIG][SIZEBIG], int sizeCol, int sizeRow);
	void FillArrayTrCh(char A[SIZESMALL][SIZESMALL], int sizeCol, int sizeRow, int IsReverseRow, int IsReverseCol, int startRow, int startCol, char B[SIZESMALL][SIZESMALL]);

	char ArrayT[SIZESMALL][SIZESMALL] = { 0 }; //������ � �������� ������������� (������ 1)
	char ArrayTChanged[SIZESMALL][SIZESMALL] = { 0 }; //������ � ������������ ������������� (������ 2, 3 ��� 4)
	char ArrayR[SIZESMALL][SIZESMALL] = { 0 }; //������ � ���������������
	char ArrayBIG[SIZEBIG][SIZEBIG] = { 0 }; //�������������� ������, ������� ������� �� ������

	char c; //����� ������������

	int resultT = FillArrayTriangle(ArrayT, 10); //��������� ������ ������������� 10�10

	int resultR = FillArrayRectangle(ArrayR, 10); //��������� ������ ��������������� 10�10

	#ifdef DEBUG //��� ����� ���������� ����� ���� ������
	printArray(ArrayT, SIZESMALL, SIZESMALL, 1, 1, 0, 0); //�������� ����������� (������ 1)

	printArray(ArrayT, SIZESMALL, -1, -1, 1, 10, 0); //�������� ����������� �������� �� ����������� - ������ � ����� � ������ (���� �� ������� � �������� �������) (������ 2)

	printArray(ArrayT, -1, SIZESMALL, 1, -1, 0, 10); //�������� ����������� (������ 3)

	printArray(ArrayT, -1, -1, -1, -1, 10, 10); //�������� ����������� �������� �� ����������� - ������ � ����� � ������ (���� �� ������� � �������� �������) (������ 4)

	printArray(ArrayR, 11, 11, 1, 1, 0, 0); //�������� �������������

	printArray(ArrayT, 11, 11, 1, 1, 0, 0); //�������� �����������
	#endif

	cout << "Please, enter one letter from A to J \n";
	cin >> c;
	
	switch (c)
	{
	case 'A':
		//������ �+

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //������ ������������ �����������

		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //��������� ����� �������
		FillResultArray(ArrayR, 11, 22, ArrayBIG, 0, 11); //��������� ������ �������
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //��������� ������ ������
		printArray1(ArrayBIG, 22, 22);
		break;

	case 'B':
		//������ �+

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //�������������� � 3� 
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //��������� ����� �������

		FillResultArray(ArrayR, 22, 11, ArrayBIG, 11, 0); //��������� ����� ������
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //��������� ������ ������

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'C':
		//������ �+

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //�������������� �� 2�
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //��������� ����� �������

		FillResultArray(ArrayT, 11, 22, ArrayBIG, 0, 11); //��������� ������ �������	

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'D':
		//������ �+

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //�������������� � 4�
		FillResultArray(ArrayTChanged, 22, 11, ArrayBIG, 11, 0); //��������� ����� ������

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //�������������� � 3� 
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //��������� ������ ������

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'E':
		//������ �+

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //�������������� �� 2�
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //��������� ����� �������

		FillResultArray(ArrayT, 11, 22, ArrayBIG, 0, 11); //��������� ������ �������

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //�������������� � 4�
		FillResultArray(ArrayTChanged, 22, 11, ArrayBIG, 11, 0); //��������� ����� ������

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //�������������� � 3�
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //��������� ������ ������

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'F':
		//������ �+

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //�������������� � 3� 
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //��������� ����� �������

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //�������������� � 4�
		FillResultArray(ArrayTChanged, 11, 22, ArrayBIG, 0, 11); //��������� ������ �������	

		FillResultArray(ArrayT, 22, 11, ArrayBIG, 11, 0); //��������� ����� ������

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //�������������� �� 2�
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //��������� ������ ������

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'G':
		//������ �+

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //�������������� � 3� 
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //��������� ����� �������

		FillResultArray(ArrayT, 22, 11, ArrayBIG, 11, 0); //��������� ����� ������

		//printArray(ArrayTChanged, SIZE2, SIZE1, 1, 1, 0, 0);

		//FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11);
		printArray1(ArrayBIG, 22, 22);
		break;

	case 'H':
		//������ �+

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //�������������� � 4�
		FillResultArray(ArrayTChanged, 11, 22, ArrayBIG, 0, 11); //��������� ������ �������	

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //�������������� �� 2�
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //��������� ������ ������

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'I':
		//������ �+

		FillResultArray(ArrayR, 11, 11, ArrayBIG, 0, 0); //��������� ����� �������
		FillResultArray(ArrayT, 11, 22, ArrayBIG, 0, 11); //��������� ������ �������
		FillResultArray(ArrayT, 22, 11, ArrayBIG, 11, 0); //��������� ����� ������
		printArray1(ArrayBIG, 22, 22);
		break;
	case 'J':
		//������ �

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //�������������� � 4�
		FillResultArray(ArrayTChanged, 11, 22, ArrayBIG, 0, 11); //��������� ������ �������
		FillResultArray(ArrayTChanged, 22, 11, ArrayBIG, 11, 0); //��������� ����� ������
		FillResultArray(ArrayR, 22, 22, ArrayBIG, 11, 11); //��������� ������ ������

		printArray1(ArrayBIG, 22, 22);
		break;
	default:
		cout << "Enter one letter from A to J \n";
		break;
	}

	system("pause");
	return 0;
}