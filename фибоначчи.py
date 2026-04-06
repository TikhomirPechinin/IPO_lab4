import time

def fibonacci_recursive(n):
    if n < 0:
        raise ValueError("Число должно быть неотрицательным")
    if n <= 1:
        return n
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

def fibonacci_iterative(n):
    if n < 0:
        raise ValueError("Число должно быть неотрицательным")
    if n <= 1:
        return n
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

def measure_time(func, n):
    start = time.time()
    result = func(n)
    end = time.time()
    return result, end - start

print("=" * 50)
print("FIBONACCI IMPLEMENTATION IN PYTHON")
print("=" * 50)

# Проверка корректности
test_values = [0, 1, 5, 10, 15, 20]
print("\nCorrectness check:")
for n in test_values:
    rec = fibonacci_recursive(n)
    it = fibonacci_iterative(n)
    print(f"  F({n}) = {rec} (recursive) = {it} (iterative)")

# Замер производительности (итеративный метод)
print("\nIterative method performance:")
for n in [1000, 5000, 10000]:
    result, elapsed = measure_time(fibonacci_iterative, n)
    print(f"  F({n}) = {str(result)[:10]}... | time: {elapsed:.6f} sec")

# Замер рекурсии (только для маленьких n)
print("\nRecursive method performance:")
for n in [10, 20, 30, 35]:
    result, elapsed = measure_time(fibonacci_recursive, n)
    print(f"  F({n}) = {result} | time: {elapsed:.6f} sec")