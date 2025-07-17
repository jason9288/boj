k, r = map(int, input().split())

ingredients = list(map(int, input().split()))
tot = list(0 for i in range(r))

for i in range(r):
    recipe = list(map(int, input().split()))
    t_ingre = ingredients
    min_usage = 9999999
    for j in range(k):
        usage = 9999999 if recipe[j] == 0 else int(ingredients[j]/recipe[j])
        if min_usage > usage:
            min_usage = usage
    tot[i] = recipe[k]*min_usage

print(max(tot))
