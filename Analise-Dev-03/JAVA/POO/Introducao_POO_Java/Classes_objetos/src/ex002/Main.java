package ex002;

public class Main {
    public static void main(String[] args) {
        // 1. Criar o Endereço da Escola
        Endereco enderecoEscola = new Endereco(
            "Av. Brasil",
            "1000", 
            "Centro",
            "Lagarto",
            "SE", 
            "49400-000"
        );

        // 2. Instanciar a Escola
        Escola escola = new Escola("Instituto de Tecnologia Java", "22.235.890/0001-90", enderecoEscola);

        // 3. Criar e Adicionar Departamentos
        // Método 1: Adicionando objeto Departamento direto
        Departamento depTI = new Departamento("Tecnologia da Informação", "DEP-TI");
        escola.adicionarDepartamento(depTI);

        // Método 2: Usando o método auxiliar criarDepartamento(String)
        escola.criarDepartamento("Engenharia de Software");
        escola.criarDepartamento("Matemática Aplicada");

        // 4. Criar e Matricular Alunos
        Aluno aluno1 = new Aluno("Ana Silva", "111.222.333-44", "2024001", "ana.silva@email.com");
        Aluno aluno2 = new Aluno("Carlos Eduardo", "222.333.444-55", "2024002", "carlos.eduardo@email.com");
        Aluno aluno3 = new Aluno("Beatriz Souza", "2024003"); // Usando o construtor simplificado

        escola.matricularAluno(aluno1);
        escola.matricularAluno(aluno2);
        escola.matricularAluno(aluno3);

        // 5. Exibir os dados completos no console
        System.out.println("=== TESTE DE IMPRESSÃO DO SISTEMA ESCOLAR ===\n");
        escola.getDados();
    }
}
