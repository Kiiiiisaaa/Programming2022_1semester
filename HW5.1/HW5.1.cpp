#include <iostream>

// Задание 1, 2
struct Dimension {
	int height;
	int depth;
	int width;
};

struct DATE {
	int day;
	int month;
	int year;
};

struct FIO {
	std::string last_name;
	std::string first_name;
	std::string patronomyc;
};

struct BOOK {
	std::string name;
	std::string authors;
	std::string publisher;
	int year;
	int length;
	int article;
};

struct PFCC {
	double proteins;
	double fats;
	double carbohydrates;
	double calories;
};

struct COPYBOOK {
	int size;
	std::string type;
	int sheets_color;
};

struct TIME {
	int hours;
	int minutes;
	int seconds;
};

struct JEANS {
	int size;
	std::string material;
	int color;
	int sex;
};

struct TV {
	int year;
	std::string model;
	std::string name;
	std::string manufacturer;
	struct Dimension dimension;
};

struct BODY_CONFIG {
	double height;
	double weight;
	double fats_percent;
	double muscles_percent;
};

struct EMPLOYEE {
	struct FIO fio;
	struct DATE birth;
	std::string occupation;
	double salary;
	int id;
};

struct PLATE {
	struct PFCC pfcc;
	std::string name;
};

struct STUDENT {
	struct FIO fio;
	struct DATE birth;
	int id;
	struct DATE end_of_studying;
	struct course;
};

struct PATIENT {
	struct FIO fio;
	struct DATE birth;
	struct DATE income;
	struct DATE outcome;
	struct BODY_CONFIG b_conf;
};

struct FAM_MEMBER {
	struct FIO fio;
	std::string role;
	int age;
};

// Задание 5

void time_input(struct TIME* time) {
	std::cout << "Input hours: ";
	std::cin >> ((*time).hours);
	std::cout << "Input minutes: ";
	std::cin >> ((*time).minutes);
	std::cout << "Input seconds: ";
	std::cin >> ((*time).seconds);
}

void PFCC_input(struct PFCC* pfcc) {
	std::cout << "Input proteins: ";
	std::cin >> ((*pfcc).proteins);
	std::cout << "Input fats: ";
	std::cin >> ((*pfcc).fats);
	std::cout << "Input carbohydrates: ";
	std::cin >> ((*pfcc).carbohydrates);
	std::cout << "Input calories: ";
	std::cin >> ((*pfcc).calories);
}
void year_input(struct DATE* date) {
	std::cout << "Input day: ";
	std::cin >> ((*date).day);
	std::cout << "Input month: ";
	std::cin >> ((*date).month);
	std::cout << "Input year: ";
	std::cin >> ((*date).year);
}

void input(struct Dimension* sizes) {
	std::cout << "Input height: ";
	std::cin >> ((*sizes).height);
	std::cout << "Input depth: ";
	std::cin >> ((*sizes).depth);
	std::cout << "Input width: ";
	std::cin >> ((*sizes).width);
}
// расчёт поверхности шкафа
int calculateSquare(struct Dimension sizes) {
	int square, square_bok, square_updown, square_front;
	// 2 боковые крышки
	square_bok = 2 * sizes.height * sizes.depth;
	// верхняя и нижняя крышки
	square_updown = 2 * sizes.width * sizes.depth;
	// 1 передняя крышка
	square_front = sizes.height * sizes.width;
	square = square_bok + square_updown + square_front;
	return square;
}


int calculateVolume(struct Dimension sizes) {
	int V = sizes.height * sizes.depth * sizes.width;
	return V;
}

float calculateDye(struct Dimension sizes, float consumption) {
	int square = calculateSquare(sizes);

	float dye_needed = square * consumption;
	return dye_needed;
}

float calculatePaintingCost(struct Dimension sizes, float consumption, float workCost, float paintCost) {
	float total_cost = 0;
	float square = calculateSquare(sizes);
	total_cost += calculateDye(sizes, consumption) * paintCost + square * workCost;
	return total_cost;
}

double calculateCupboardCost(struct Dimension sizes, float cupboardCost) {
	return calculateSquare(sizes) * cupboardCost;
}

float calculateWeight(struct Dimension sizes, float density) {
	return calculateSquare(sizes) * density;
}

float calculateDeliveryCost(struct Dimension sizes, float weight, int floorsCount, float riseCost, float deliveryCost) {
	return weight * riseCost * floorsCount + deliveryCost;
}

double calculateCost(struct Dimension cupboard, float cupboardCost, float paintConsumption, float paintCost, float paintWorkCost, float weight, int floorsCount, float riseCost, float deliveryCost) {
	double cupboard_cost = calculateCupboardCost(cupboard, cupboardCost);
	float painting_cost = calculatePaintingCost(cupboard, paintConsumption, paintWorkCost, paintCost);
	float delivery_cost = calculateDeliveryCost(cupboard, weight, floorsCount, riseCost, deliveryCost);
	double total_cost = cupboard_cost + painting_cost + delivery_cost;
	std::cout << "\nCupboard cost: " << cupboard_cost;
	std::cout << "\nPainting cost: " << painting_cost;
	std::cout << "\nDelivery cost: " << delivery_cost;
	return total_cost;
}



int main() {

	// Задание 3
	struct EMPLOYEE worker1 = { {"Пугачева", "Алла", "Борисовна"}, {15, 04, 1949}, "singer", 1000000, 1234};
	struct PFCC pfcc = { 123, 456, 789, 1200.123 };
	struct DATE date = { 20, 8, 2004 };
	struct TIME time = { 7, 28, 56 };
	struct FIO fio = { "Агузарова", "Жанна", "Хасановна" };

	// Задание 4
	struct TIME* meels;
	meels = new struct TIME[24 * 2];
	meels[0] = { 8, 0, 0 };
	meels[1] = { 14, 0, 0 };
	meels[2] = { 20, 0, 0 };

	struct FAM_MEMBER* family;
	family = new struct FAM_MEMBER[50];
	family[0] = { {"Фамилия1","Имя1","Отчество1"}, "Мать"};
	family[1] = { {"Фамилия2","Имя2","Отчество2"}, "Отец" };
	family[2] = { {"Фамилия3","Имя3","Отчество3"}, "Дочь" };

	float paintConsumption = 0.8, paintWorkCost = 15.00, paintCost = 20.00;
	// стоимость материала шкафа за м2
	float cupboardCost = 650;
	// вес кг/м2
	float weight = 0.9;
	// число этажей
	int floorsCount = 5;
	float deliveryCost = 500.00;
	float riseCost = 2.50;
	struct Dimension cupboard;
	std::cout << "CUPBOARD PARAMETERS\n";
	input(&cupboard);
	double cost;
	cost = calculateCost(cupboard, cupboardCost, paintConsumption, paintCost, paintWorkCost, weight, floorsCount, riseCost, deliveryCost);
	std::cout << "\nTotal cost: " << cost;
	return 0;





}