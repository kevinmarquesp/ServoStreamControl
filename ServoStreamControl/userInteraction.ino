/**
 * Essa função para a execução do programa e espera o usuário enviar alguma
 * coisa na porta serial.
 * @returns String: O que o usuário escreveu na comunicação serial
 */
inline String readSerialInputString(void) {
    while (!Serial.available())
        continue;

    const String userInputString = Serial.readStringUntil('\n');
    return userInputString;
}
