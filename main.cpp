#include <iostream>
#include <cstdlib>


int getRandomNumber(const int min, const int max){
    int random_result = min + std::rand() % max;
    return random_result;
}

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = getRandomNumber(0, 50);
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void findPairs(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                std::cout << "Пара найдена: " << arr[i] << "+" << arr[j] << "=" << target << std::endl;
            }
        }
    }
}


int main() {
    std::srand(static_cast<unsigned int>(time(nullptr)));  // Инициализация рандомайзера, помещение зерна (seed)
    
    int size = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];  // Инициализация динамического массива (выделение памяти из кучи)

    fillArray(arr, size);

    std::cout << "Ваш массив: [ ";
    printArray(arr, size);
    std::cout << "]" << std::endl;

    int target = 0;
    std::cout << "Введи число для поиска суммы в массиве: ";
    std::cin >> target;

    findPairs(arr, size, target);

    delete[] arr;  // Возвращаем выделенную память

    return 0;
}
