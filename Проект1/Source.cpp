#include <iostream>
using namespace std;
#define SIZESMALL 11 //кол-во элементов в строке и столбце
#define SIZEBIG 22 //размер результирующего массива
//#define DEBUG 


//альтернатива
#ifdef DEBUG
void printArray(char A[SIZESMALL][SIZESMALL], int sizeCol, int sizeRow, int IsReverseRow, int IsReverseCol, int startRow, int startCol)
//функция используется для отладки
{
	int i;
	int j;

	for (j = startCol; -1 * IsReverseCol*j > sizeCol*IsReverseCol*-1; ) //идем по столбцам, выражение *IsReverse*-1 меняет знак в зависимости от того печатаем массив с конца или с начала
																		//если массив печатаем сначала: i<10 - идентично -i>-10 (IsReverse передаем 1), если массим печатаем с конца: i>-1 (IsReverse передаем -1 и при умножении на -1 получаем +знак)
	{
		for (i = startRow; -1 * IsReverseRow*i > sizeRow*IsReverseRow*-1; ) //идем по строкам
		{
			cout << A[j][i];
			i = i + 1 * IsReverseRow; //увеличиваем, либо уменьшаем счетчик
		}
		cout << "\n";
		j = j + 1 * IsReverseCol; //увеличиваем, либо уменьшаем счетчик
	}
	//cout << "\n";
}
#endif

void printArray1(char A[SIZEBIG][SIZEBIG],
	int sizeCol, //до куда доходим по столбцам
	int sizeRow) //до куда доходим по сторокам

{
	int i;
	int j;

	cout << "Result Array" << endl;
	for (j = 0; j < sizeCol; j++)
	{
		for (i = 0; i < sizeRow; i++) //идем по строкам
		{
			cout << A[j][i];
		}
		cout << "\n";
	}
	//cout << "\n";
}

//Функция для переворачивания треугольника
void FillArrayTrCh(
	char A[SIZESMALL][SIZESMALL], //массив с треугольником на вход (фигура 1)
	int sizeCol, //индекс, на котором прекражается вертикальное заполнение массива (если идем вперед, то = 11, если идем назад, то = -1
	int sizeRow, //индекс, на котором прекражается горизонтальное заполнение массива (если идем вперед, то = 11, если идем назад, то = -1
	int IsReverseRow, //признак переворачивания строк исходного массива: -1 - переворачиваем, 1 - не переворачиваем
	int IsReverseCol, //признак переворачивания столбцов исходного массива: -1 - переворачиваем, 1 - не переворачиваем
	int startRow, //откуда начинать идти по строке: идем сначала = 0 (не переворачиваем строку), идем с конца = 10 (переворачиваем строку)
	int startCol, //откуда начинать идти по столбцам: идем сначала = 0 (не переворачиваем столбец), идем с конца = 10 (переворачиваем столбец)
	char B[SIZESMALL][SIZESMALL]) //перевернутый треугольник (фигура 2, 3 или 4 в завивисомсти от переданных параметров
{
	int i;
	int j;
	int n = 0; //индекс строки массива В
	int m = 0; //индекс столбца массива В

	for (j = startCol; -1 * IsReverseCol*j > sizeCol*IsReverseCol*-1; ) //идем по столбцам, выражение *IsReverse*-1 меняет знак в зависимости от того печатаем массив с конца или с начала
																		//если массив печатаем сначала: i<10 - идентично -i>-10 (IsReverse передаем 1), если массим печатаем с конца: i>-1 (IsReverse передаем -1 и при умножении на -1 получаем +знак)
	{
		for (i = startRow; -1 * IsReverseRow*i > sizeRow*IsReverseRow*-1; ) //идем по строкам
		{
			B[n][m] = A[j][i];
			i = i + 1 * IsReverseRow; //увеличиваем, либо уменьшаем счетчик
			m++;
		}
		//cout << "\n";
		m = 0;
		j = j + 1 * IsReverseCol; //увеличиваем, либо уменьшаем счетчик
		n++;
	}
	//cout << "\n";
}

//Функция заполнения результирующего массива (который будем выводить на печать)
void FillResultArray(char
	A[SIZESMALL][SIZESMALL], //массив который нужно вставить в результирующий массив
	int sizeCol, //до куда доходим по столбцам
	int sizeRow, //до куда доходим по сторокам
	char B[SIZEBIG][SIZEBIG], //результирующий массив
	int BstartRow, // указывает с какой строки заполнять
	int BstartCol) // указывает с какого места в строке заполнять
{
	int i;
	int j;

	for (j = BstartRow; j < sizeCol; j++)
	{
		for (i = BstartCol; i < sizeRow; i++) //идем по строкам
		{
			B[j][i] = A[j - BstartRow][i - BstartCol]; //указываем с какой позиции заполнять массив
		}
	}
	//cout << "\n";
}


int FillArrayTriangle(char Array[SIZESMALL][SIZESMALL], int size) //заполнение массива пробелами и * в виде прямоугольного треугольника размером sizeХsize ячеек (Фигура 1)
{
	size = 10; //количество ячеек в массиве, получается матрица 11х11 (т.к. цикл идет с 0 до 10)
	int i;
	int j;
	
	for (j = 0; j <= size; j++) //идем по столбцам
	{
		for (i = 0; i <= size; i++) //идем по строкам
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

int FillArrayRectangle(char Array[SIZESMALL][SIZESMALL], int size) //заполнение массива пробелами и * в виде прямоугольного треугольника размером sizeХsize ячеек
{
	int i;
	int j;
	int k = 0;

	for (j = 0; j <= size; j++) //идем по столбцам
	{
		for (i = 0; i <= size; i++) //идем по строкам
		{

			Array[j][i] = '*';
		}
		k++;
	}

	return 0;
}

int main()
//принцип работы: создаем две фигуры - треугольник(Фигура 1) и прямоугольник, для переворачивания треугольника из Фигуры 1 в Фигуру 2,3 или 4 используем функцию переворачивания треугольника
//делим область печати на 4 квадрата: левый верхний / нижний, правый верхний / нижний
//берем фигуру (прямоугольник или треугольник), если нужно - переворачиваем треугольник, заполняем нужные фигуры по 4м областям печати
//печатаем получившийся массив ArrayBIG
{
	//setlocale(LC_ALL, "Russian");
	
	void printArray(char A[SIZESMALL][SIZESMALL], int sizeCol, int sizeRow, int IsReverseRow, int IsReverseCol, int startRow, int startCol);
	int FillArrayTriangle(char Array1[SIZESMALL][SIZESMALL], int size1);
	int FillArrayRectangle(char Array2[SIZESMALL][SIZESMALL], int size);
	void FillResultArray(char
		A[SIZESMALL][SIZESMALL],
		int sizeCol, //до куда доходим по столбцам
		int sizeRow, //до куда доходим по сторокам
					 //int startRow, //с какого места идем по строкам
					 //int startCol, //с какого места идем по столбцам
		char B[SIZEBIG][SIZEBIG],
		int BstartRow, // с каого ряда заполнять
		int BstartCol); // с какого места в строке заполнять

	void printArray1(char A[SIZEBIG][SIZEBIG], int sizeCol, int sizeRow);
	void FillArrayTrCh(char A[SIZESMALL][SIZESMALL], int sizeCol, int sizeRow, int IsReverseRow, int IsReverseCol, int startRow, int startCol, char B[SIZESMALL][SIZESMALL]);

	char ArrayT[SIZESMALL][SIZESMALL] = { 0 }; //массив с исходным треугольником (Фигура 1)
	char ArrayTChanged[SIZESMALL][SIZESMALL] = { 0 }; //массив с перевернутым треугольником (Фигура 2, 3 или 4)
	char ArrayR[SIZESMALL][SIZESMALL] = { 0 }; //массив с прямоугольником
	char ArrayBIG[SIZEBIG][SIZEBIG] = { 0 }; //результирующий массив, который выводим на печать

	char c; //выбор пользователя

	int resultT = FillArrayTriangle(ArrayT, 10); //заполняем массив треугольником 10х10

	int resultR = FillArrayRectangle(ArrayR, 10); //заполняем массив прямоугольником 10х10

	#ifdef DEBUG //тут можно посмотреть какие есть фигуры
	printArray(ArrayT, SIZESMALL, SIZESMALL, 1, 1, 0, 0); //печатаем треугольник (фигура 1)

	printArray(ArrayT, SIZESMALL, -1, -1, 1, 10, 0); //печатаем треугольник наоборот по горизонтали - строки с конца в начало (идем по строкам в обратную сторону) (фигура 2)

	printArray(ArrayT, -1, SIZESMALL, 1, -1, 0, 10); //печатаем треугольник (фигура 3)

	printArray(ArrayT, -1, -1, -1, -1, 10, 10); //печатаем треугольник наоборот по горизонтали - строки с конца в начало (идем по строкам в обратную сторону) (фигура 4)

	printArray(ArrayR, 11, 11, 1, 1, 0, 0); //печатаем прямоугольник

	printArray(ArrayT, 11, 11, 1, 1, 0, 0); //печатаем треугольник
	#endif

	cout << "Please, enter one letter from A to J \n";
	cin >> c;
	
	switch (c)
	{
	case 'A':
		//ФИГУРА а+

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //делаем перевернутый треугольник

		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //заполняем левый верхний
		FillResultArray(ArrayR, 11, 22, ArrayBIG, 0, 11); //заполняем правый верхний
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //заполняем правый нижний
		printArray1(ArrayBIG, 22, 22);
		break;

	case 'B':
		//ФИГУРА б+

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //переворачиваем в 3й 
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //заполняем левый верхний

		FillResultArray(ArrayR, 22, 11, ArrayBIG, 11, 0); //заполняем левый нижний
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //заполняем правый нижний

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'C':
		//ФИГУРА в+

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //переворачиваем во 2й
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //заполняем левый верхний

		FillResultArray(ArrayT, 11, 22, ArrayBIG, 0, 11); //заполняем правый верхний	

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'D':
		//ФИГУРА г+

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //переворачиваем в 4й
		FillResultArray(ArrayTChanged, 22, 11, ArrayBIG, 11, 0); //заполняем левый нижний

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //переворачиваем в 3й 
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //заполняем правый нижний

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'E':
		//ФИГУРА д+

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //переворачиваем во 2й
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //заполняем левый верхний

		FillResultArray(ArrayT, 11, 22, ArrayBIG, 0, 11); //заполняем правый верхний

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //переворачиваем в 4й
		FillResultArray(ArrayTChanged, 22, 11, ArrayBIG, 11, 0); //заполняем левый нижний

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //переворачиваем в 3й
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //заполняем правый нижний

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'F':
		//ФИГУРА е+

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //переворачиваем в 3й 
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //заполняем левый верхний

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //переворачиваем в 4й
		FillResultArray(ArrayTChanged, 11, 22, ArrayBIG, 0, 11); //заполняем правый верхний	

		FillResultArray(ArrayT, 22, 11, ArrayBIG, 11, 0); //заполняем левый нижний

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //переворачиваем во 2й
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //заполняем правый нижний

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'G':
		//ФИГУРА ж+

		FillArrayTrCh(ArrayT, -1, 11, 1, -1, 0, 10, ArrayTChanged); //переворачиваем в 3й 
		FillResultArray(ArrayTChanged, 11, 11, ArrayBIG, 0, 0); //заполняем левый верхний

		FillResultArray(ArrayT, 22, 11, ArrayBIG, 11, 0); //заполняем левый нижний

		//printArray(ArrayTChanged, SIZE2, SIZE1, 1, 1, 0, 0);

		//FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11);
		printArray1(ArrayBIG, 22, 22);
		break;

	case 'H':
		//ФИГУРА з+

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //переворачиваем в 4й
		FillResultArray(ArrayTChanged, 11, 22, ArrayBIG, 0, 11); //заполняем правый верхний	

		FillArrayTrCh(ArrayT, SIZESMALL, -1, -1, 1, 10, 0, ArrayTChanged); //переворачиваем во 2й
		FillResultArray(ArrayTChanged, 22, 22, ArrayBIG, 11, 11); //заполняем правый нижний

		printArray1(ArrayBIG, 22, 22);
		break;
	case 'I':
		//ФИГУРА и+

		FillResultArray(ArrayR, 11, 11, ArrayBIG, 0, 0); //заполняем левый верхний
		FillResultArray(ArrayT, 11, 22, ArrayBIG, 0, 11); //заполняем правый верхний
		FillResultArray(ArrayT, 22, 11, ArrayBIG, 11, 0); //заполняем левый нижний
		printArray1(ArrayBIG, 22, 22);
		break;
	case 'J':
		//ФИГУРА к

		FillArrayTrCh(ArrayT, -1, -1, -1, -1, 10, 10, ArrayTChanged); //переворачиваем в 4й
		FillResultArray(ArrayTChanged, 11, 22, ArrayBIG, 0, 11); //заполняем правый верхний
		FillResultArray(ArrayTChanged, 22, 11, ArrayBIG, 11, 0); //заполняем левый нижний
		FillResultArray(ArrayR, 22, 22, ArrayBIG, 11, 11); //заполняем правый нижний

		printArray1(ArrayBIG, 22, 22);
		break;
	default:
		cout << "Enter one letter from A to J \n";
		break;
	}

	system("pause");
	return 0;
}