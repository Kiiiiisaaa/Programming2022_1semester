#include<stdio.h>
#include<locale.h>
#include<math.h>

int main() {
    setlocale(LC_ALL, "rus");
    int AB, BC, AC;
    float S, p;
    printf("������� ��� ������� ������������: ");
    scanf_s("%d %d %d", &AB, &BC, &AC);
    if (AB > 0 && BC > 0 && AC > 0) {
        if (AB + BC >= AC && AB + AC >= BC && BC + AC >= AB) {
            p = (AB + BC + AC) * 0.5;
            S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
            printf("���������: S=%.2f\n", S);
        } else {
            printf("������������ �� ����������.\n");
        }
    } else {
        printf("�� �������� ;-)");
    }
    system("pause");
    return 0;
}
