# Comunicação Serial Simulink-Arduino (Controle de Servo Motor)

Este repositório apresenta os códigos relacionados ao controle de um servo motor usando a comunicação serial entre um Arduino e o software Simulink. O fluxo de informação se dá do Simulink para o arduíno. Os códigos realizam as  seguintes funcionalidades:

## Arduino (Código Arduino)

### Propósito:
O código Arduino permite controlar a posição de um servo motor com base nos comandos recebidos via comunicação serial do Simulink.

### Funcionamento:
1. Inclui a biblioteca Servo.h para controle do servo motor.
2. Cria um objeto para controlar o servo motor.
3. Define uma estrutura de união (union) para converter valores float em bytes.
4. Inicializa um buffer e variáveis para armazenar os dados.
5. Inicia a comunicação serial a 115200 bauds.
6. Configura a conexão com o servo motor.
7. Entra em um loop principal.
8. Lê caracteres da porta serial.
9. Se um caractere 'A' for recebido, lê um valor float da porta serial e o utiliza para controlar a posição do servo.
10. Envia o valor lido de volta para a porta serial.
11. Lida com erros caso o header recebido do Simulink não seja o caractere 'A'.

## Simulink (Modelo Simulink)

### Propósito:
O modelo Simulink é projetado para enviar comandos para o Arduino via comunicação serial, permitindo o controle remoto do servo motor.

### Funcionamento:
1. Utiliza blocos Simulink para gerar comandos de controle para o Arduino.
2. Esses comandos são enviados para o Arduino via bloco "Serial Send".
3. Os comandos controlam a posição do servo motor com base em entradas, enviadas do Simulink.

Obs: Para a comunicação serial é necessário utilizar a biblioteca "Instrument Control Toolbox", caso você não tenha, é necessário instalar.

## Uso:
1. Carregue o código Arduino no Arduino.
2. Execute o modelo Simulink no ambiente do Simulink.
3. O Simulink envia comandos ao Arduino via comunicação serial.
4. O Arduino interpreta os comandos e controla a posição do servo motor em conformidade.

Lembre-se de configurar corretamente a porta COM, a taxa de baud e o hardware no Simulink e no Arduino para garantir que a comunicação ocorra sem problemas.

Esperamos que esses códigos sejam úteis para entender e iniciar a comunicação serial entre o Simulink e o Arduino.

Para qualquer dúvida ou problema, sinta-se à vontade para entrar em contato ou contribuir para este repositório.
