/*
Task priorities and delays are based on the last digit of your student ID
If your student ID ends with X, use the following values:
Task1 priority: X+1 (if X<7, otherwise 2)
Task2 priority: 2
Task1 delay: (X+1)*10 ms
Task2 delay: (8-X)*10 ms
*/
void Task1(void *pvParameters) {
    while(1) {
        printf("A");
        vTaskDelay(pdMS_TO_TICKS(DELAY1)); // DELAY1 based on your student ID
    }
}

void Task2(void *pvParameters) {
    while(1) {
        printf("B");
        vTaskDelay(pdMS_TO_TICKS(DELAY2)); // DELAY2 based on your student ID
    }
}

void main() {
    xTaskCreate(Task1, "Task1", 128, NULL, PRIORITY1, NULL); // PRIORITY1 from your ID
    xTaskCreate(Task2, "Task2", 128, NULL, PRIORITY2, NULL); // PRIORITY2 = 2
    vTaskStartScheduler();
}