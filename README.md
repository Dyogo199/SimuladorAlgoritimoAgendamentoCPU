
# 🖥️ Simulador de Algoritmos de Agendamento de CPU 🚀

Bem-vindo ao **Simulador de Algoritmos de Agendamento de CPU**! Este projeto foi desenvolvido em **C** para demonstrar e comparar o funcionamento dos principais algoritmos de escalonamento de processos em sistemas operacionais. Explore como cada algoritmo impacta o tempo de execução, o tempo de espera e a eficiência da CPU.

---

## 📚 **Sobre o Projeto**

Este simulador permite que você experimente na prática os seguintes algoritmos:
1. **FIFO (First In First Out)** - Processos executados na ordem de chegada.
2. **Round Robin** - Cada processo recebe um tempo fixo (quantum) para execução.
3. **Priority Scheduling**:
   - **Com Preempção** - Processos de maior prioridade podem interromper outros.
   - **Sem Preempção** - Prioridade é respeitada, mas sem interrupções.
4. **SJF (Shortest Job First)** (Pré-emptivo e Não-Preemptivo) - O menor tempo de burst é priorizado.

O simulador calcula métricas importantes como:
- **Tempo de Conclusão (Completion Time)**.
- **Tempo de Retorno (Turnaround Time)**.
- **Tempo de Espera (Waiting Time)**.

---

## 🛠️ **Requisitos para Uso**
Para compilar e executar este projeto, você precisará de:
- **GCC** (GNU Compiler Collection) ou outro compilador compatível com C.
- Um terminal ou IDE de sua escolha (ex.: CLion, VS Code).

---

## 🚀 **Como Configurar e Executar**

### **1. Clonar o Repositório**
Use o comando abaixo para clonar o repositório no seu ambiente local:
```bash
git clone https://github.com/Dyogo199/SimuladorAlgoritimoAgendamentoCPU.git
cd SimuladorAlgoritimoAgendamentoCPU
```

### **2. Compilar o Código**
Compile o programa usando o **GCC**:
```bash
gcc -o cpu_scheduler main.c
```

### **3. Executar o Programa**
Execute o programa com:
```bash
./cpu_scheduler
```

No Windows:
```cmd
cpu_scheduler.exe
```

---

## 🎮 **Manual de Uso**

1. **Insira o número de processos:**
   - Você será solicitado a informar quantos processos deseja simular.
   - Exemplo:
     ```
     Digite o número de processos: 3
     ```

2. **Digite os tempos de chegada, burst e prioridade de cada processo:**
   - Para cada processo, insira:
     - Tempo de chegada (arrival time).
     - Tempo de execução (burst time).
     - Prioridade (menor número = maior prioridade).
   - Exemplo:
     ```
     Digite tempo de chegada, burst e prioridade para P1: 0 5 1
     Digite tempo de chegada, burst e prioridade para P2: 1 3 2
     Digite tempo de chegada, burst e prioridade para P3: 2 8 3
     ```

3. **Selecione o algoritmo desejado no menu:**
   - O programa exibirá um menu com as opções disponíveis:
     ```
     Escolha o algoritmo:
     1. FIFO (First In First Out)
     2. Round Robin
     3. Priority Scheduling (Preemptive)
     4. Priority Scheduling (Non-Preemptive)
     5. Sair
     Opção:
     ```

4. **Siga as instruções:**
   - Para **Round Robin**, você será solicitado a informar o quantum.
   - O programa calculará os tempos e exibirá os resultados no terminal.

---

## 🏆 **Exemplo de Resultado**

Para a entrada:
- **Processos:** P1, P2, P3.
- **Chegada/Burst/Prioridade:** `P1: 0/5/1`, `P2: 1/3/2`, `P3: 2/8/3`.
- Algoritmo: FIFO.

Saída:
```
=== FIFO (First In First Out) ===
PID	Arrival	Burst	Completion	Waiting	Turnaround
1	0	5	5		0	5
2	1	3	8		4	7
3	2	8	16		6	14
```

---

## ✨ **Destaques do Projeto**

- **Didático**: Ideal para estudantes e entusiastas aprenderem sobre sistemas operacionais.
- **Flexível**: Inclui algoritmos preemptivos e não preemptivos.
- **Cálculos Precisos**: Métricas como tempos de espera e retorno são calculadas automaticamente.
- **Simples e Intuitivo**: Funciona direto no terminal sem necessidade de interfaces complexas.

---

## 🛠️ **Melhorias Futuras**
- Adicionar visualização gráfica dos tempos de execução.
- Implementar suporte a mais algoritmos (ex.: Multilevel Queue).
- Exportar resultados para arquivos.

---

## 📄 **Licença**

Este projeto está licenciado sob a licença MIT. Sinta-se à vontade para usá-lo, modificá-lo e compartilhá-lo.

---

💡 **Desenvolvido por Dyogo** | Entre em contato para colaborações ou dúvidas. Aproveite o aprendizado! 🚀
```

---

### **Características do README**
- **Criatividade:** Apresentação atraente e organizada.
- **Clareza:** Instruções claras sobre como usar o programa.
- **Informações Técnicas:** Explica conceitos como tempos de CPU e algoritmos de escalonamento.
- **Engajamento:** Chama atenção para melhorias futuras e como expandir o projeto.

Se precisar de mais ajustes ou personalizações, me avise! 😊
