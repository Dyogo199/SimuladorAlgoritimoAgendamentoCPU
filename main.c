#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

// Estrutura do Processo
typedef struct {
    int pid;        // ID do processo
    int arrival;    // Tempo de chegada
    int burst;      // Tempo de execução
    int priority;   // Prioridade (menor número = maior prioridade)
    int remaining;  // Tempo restante (para algoritmos preemptivos)
    int completion; // Tempo de conclusão
    int waiting;    // Tempo de espera
    int turnaround; // Tempo de retorno
} Process;

// Ordenar processos por tempo de chegada
void sort_by_arrival(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival > processes[j + 1].arrival) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Algoritmo FIFO (First In First Out)
void fifo(Process processes[], int n) {
    int current_time = 0;
    sort_by_arrival(processes, n);

    printf("\n=== FIFO (First In First Out) ===\n");
    printf("PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival) {
            current_time = processes[i].arrival;
        }
        processes[i].completion = current_time + processes[i].burst;
        processes[i].turnaround = processes[i].completion - processes[i].arrival;
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
        current_time = processes[i].completion;

        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", processes[i].pid, processes[i].arrival,
               processes[i].burst, processes[i].completion, processes[i].waiting, processes[i].turnaround);
    }
}

// Algoritmo Round Robin
void round_robin(Process processes[], int n, int quantum) {
    int current_time = 0, completed = 0;
    Process rr[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        rr[i] = processes[i];
        rr[i].remaining = rr[i].burst;
    }

    printf("\n=== Round Robin (Quantum: %d) ===\n", quantum);
    printf("PID\tCompletion\tWaiting\tTurnaround\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rr[i].remaining > 0 && rr[i].arrival <= current_time) {
                int exec_time = (rr[i].remaining > quantum) ? quantum : rr[i].remaining;
                rr[i].remaining -= exec_time;
                current_time += exec_time;

                if (rr[i].remaining == 0) {
                    rr[i].completion = current_time;
                    rr[i].turnaround = rr[i].completion - rr[i].arrival;
                    rr[i].waiting = rr[i].turnaround - rr[i].burst;
                    completed++;

                    printf("%d\t%d\t\t%d\t%d\n", rr[i].pid, rr[i].completion,
                           rr[i].waiting, rr[i].turnaround);
                }
            }
        }
    }
}

// Algoritmo de Prioridade
void priority_scheduling(Process processes[], int n, bool preemptive) {
    int current_time = 0, completed = 0;
    int remaining[MAX_PROCESSES];
    for (int i = 0; i < n; i++) remaining[i] = processes[i].burst;

    printf("\n=== Priority Scheduling (%s) ===\n", preemptive ? "Preemptive" : "Non-Preemptive");
    printf("PID\tCompletion\tWaiting\tTurnaround\n");

    while (completed < n) {
        int highest_priority = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= current_time && remaining[i] > 0) {
                if (highest_priority == -1 || processes[i].priority < processes[highest_priority].priority) {
                    highest_priority = i;
                }
            }
        }

        if (highest_priority == -1) {
            current_time++;
        } else {
            if (preemptive) {
                remaining[highest_priority]--;
                current_time++;
            } else {
                current_time += remaining[highest_priority];
                remaining[highest_priority] = 0;
            }

            if (remaining[highest_priority] == 0) {
                completed++;
                processes[highest_priority].completion = current_time;
                processes[highest_priority].turnaround = processes[highest_priority].completion - processes[highest_priority].arrival;
                processes[highest_priority].waiting = processes[highest_priority].turnaround - processes[highest_priority].burst;

                printf("%d\t%d\t\t%d\t%d\n", processes[highest_priority].pid,
                       processes[highest_priority].completion,
                       processes[highest_priority].waiting,
                       processes[highest_priority].turnaround);
            }
        }
    }
}

int main() {
    int n, choice, quantum;
    Process processes[MAX_PROCESSES];

    printf("Digite o numero de processos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Digite tempo de chegada, burst e prioridade para P%d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival, &processes[i].burst, &processes[i].priority);
    }

    while (1) {
        printf("\nEscolha o algoritmo:\n");
        printf("1. FIFO (First In First Out)\n");
        printf("2. Round Robin\n");
        printf("3. Priority Scheduling (Preemptive)\n");
        printf("4. Priority Scheduling (Non-Preemptive)\n");
        printf("5. Sair\n");
        printf("Opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fifo(processes, n);
                break;
            case 2:
                printf("Digite o quantum: ");
                scanf("%d", &quantum);
                round_robin(processes, n, quantum);
                break;
            case 3:
                priority_scheduling(processes, n, true);
                break;
            case 4:
                priority_scheduling(processes, n, false);
                break;
            case 5:
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
