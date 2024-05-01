import math

computed = {}

# def my_func(n, k):
#     my_sum = 0
#     for i in range(1, n-1):
#         for j in range(1, n-i):
#             my_sum += math.comb(n, i) * math.comb(n-i, j)

#     print(f"Total graphs according to my function: {my_sum}")

def sterling2(n, k):
	key = str(n) + "," + str(k)
	if key in computed.keys():
		return computed[key]
	
	if n == k == 0:
		return 1
	if (n > 0 and k == 0) or (n == 0 and k > 0):
		return 0
	if n == k:
		return 1
	if k > n:
		return 0
	result = k * sterling2(n - 1, k) + sterling2(n - 1, k - 1)
	computed[key] = result
	return result
         

if __name__ == "__main__":
    n = int(input("Number of vertices: "))
    n = math.comb(n, 2)
    k = int(input("Number of edge types: "))
    reduced_graphs = sterling2(n, k)
    print(f"Total graphs: {reduced_graphs*math.factorial(k)}")
    print(f"Reduced Number of Graphs: {reduced_graphs}")
    # my_func(n, k)