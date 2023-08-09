MOD = int(1e9 + 7)

def count_combinations(n, m, k):
    # Caso base: se não há mais dados restantes
    if n == 0:
        # Se o valor mínimo da soma é 0, retorna 1, caso contrário retorna 0
        return 1 if k == 0 else 0
    
    # Inicializa o número de combinações como 0
    combinations = 0
    
    # Tenta todas as faces do dado
    for i in range(1, m + 1):
        # Se o valor da face atual for menor ou igual ao valor mínimo da soma
        if i <= k:
            # Chama recursivamente a função para os dados restantes
            combinations += count_combinations(n - 1, m, k - i)
    
    return combinations % MOD

def calculate_combinations():
    combinations = count_combinations(3,6,1)
    print(combinations)

calculate_combinations()