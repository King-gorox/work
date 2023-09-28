using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        Console.Write("Введите количество строк (n): ");
        int n = int.Parse(Console.ReadLine());
        Console.Write("Введите количество столбцов (m): ");
        int m = int.Parse(Console.ReadLine());
        Console.Write("Введите символ для заливки: ");
        char fillChar = char.Parse(Console.ReadLine());
        Console.Write("Введите вероятность появления символа: ");
        double plusProbability = double.Parse(Console.ReadLine());
        char[,] matrix = new char[n, m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i, j] = ' ';
            }
        }

        Random random = new Random();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (random.NextDouble() < plusProbability)
                {
                    matrix[i, j] = '+';
                }
            }
        }

        // Вывод исходной матрицы
        Console.WriteLine("Исходная матрица:");
        PrintMatrix(matrix);
        Console.Write("Введите координату строки (x) для заливки: ");
        int x = int.Parse(Console.ReadLine());
        Console.Write("Введите координату столбца (y) для заливки: ");
        int y = int.Parse(Console.ReadLine());
        char originalChar = matrix[x, y];
        int fillCount = FloodFill(matrix, x, y, fillChar, originalChar);
        // Вывод матрицы после заливки
        Console.WriteLine("Матрица после заливки:");
        PrintMatrix(matrix);

        int emptyCellCount = CountCells(matrix, ' ');
        int fillCharCount = CountCells(matrix, fillChar);
        int originalCharCount = CountCells(matrix, originalChar);

        Console.WriteLine($"Количество пустых ячеек: {emptyCellCount}");
        Console.WriteLine($"Количество символов '{fillChar}' после заливки: {fillCharCount}");
        Console.WriteLine($"Количество символов '{originalChar}' изначально: {originalCharCount}");
        Console.WriteLine($"Число вызовов рекурсивной функции для заливки: {fillCount}");
    }

    static void PrintMatrix(char[,] matrix)
    {
        int n = matrix.GetLength(0);
        int m = matrix.GetLength(1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                Console.Write(matrix[i, j] + " ");
            }
            Console.WriteLine();
        }
    }

    static int FloodFill(char[,] matrix, int x, int y, char fillChar, char originalChar)
    {
        int fillCount = 0;
        int n = matrix.GetLength(0);
        int m = matrix.GetLength(1);
        Stack<(int, int)> stack = new Stack<(int, int)>();
        stack.Push((x, y));
        while (stack.Count > 0)
        {
            (int currentX, int currentY) = stack.Pop();

            if (currentX >= 0 && currentX < n && currentY >= 0 && currentY < m && matrix[currentX, currentY] == originalChar)
            {
                matrix[currentX, currentY] = fillChar;
                fillCount++;
                stack.Push((currentX + 1, currentY));
                stack.Push((currentX - 1, currentY));
                stack.Push((currentX, currentY + 1));
                stack.Push((currentX, currentY - 1));
            }
        }

        return fillCount;
    }

    static int CountCells(char[,] matrix, char targetChar)
    {
        int count = 0;
        int n = matrix.GetLength(0);
        int m = matrix.GetLength(1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i, j] == targetChar)
                {
                    count++;
                }
            }
        }
        return count;
    }
}
