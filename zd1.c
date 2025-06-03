#include <stdio.h>
#include <time.h>
#include <unistd.h>

void print_times() {
    struct timespec ts;

    clock_gettime(CLOCK_REALTIME, &ts);
    printf("CLOCK_REALTIME:  %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    printf("CLOCK_MONOTONIC: %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);
}

int main() {
    printf("Перед зміною часу:\n");
    print_times();

    printf("\nЗмініть системний час у іншому терміналі (наприклад: sudo date -s \"+2 minutes\"), потім натисніть Enter...\n");
    getchar();

    printf("\nПісля зміни часу:\n");
    print_times();

    return 0;
}
