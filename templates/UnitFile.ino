// você deve incluir a biblioteca local do sketch sem caminho nenhum, o processo
// de build dos testes já importa cada arquivo dentro de `src/` individualmente.
// Por exemplo, use `<BaseCommand.h>` ao invés de `<src/shell/BaseCommand.h>`

// todo teste precisa ter o nome do método e/ou o nome da classe para contexto,
// e a descrição do teste precisa ser objetivo e simples; seguindo o padrão que
// o Jest usa (faz de conta que essa macro se chama `it()` como no Jest).
test(__ClassName_methodName__, should_pass_because_it_is_a_mere_template)
{
    // esses `__` no nome do teste serve pra tonar a identificações de cada um
    // no output do AUnit, mais fáicl pra ver qual deu errado e qual passou...
    assertTrue(true);
}