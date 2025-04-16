fibonacci() {
local n=$1
local a=$2
local b=$3

if (( n <= 0 )); then
return
fi

echo "$a"

local next=$((a + b))
fibonacci $((n - 1)) "$b" "$next"
}

read -p "Введите первое число: " first
read -p "Введите второе число: " second
read -p "Введите количество чисел: " count

if [[ ! "$first" =~ ^[0-9]+$ || ! "$second" =~ ^[0-9]+$ || ! "$count" =~ ^[0-9]+$ ]]; then
echo "Ошибка: Введите целые неотрицательные числа."
exit 1
fi

if (( count <= 0 )); then
echo "Ошибка: Количество чисел должно быть положительным."
exit 1
fi

echo "Числа Фибоначчи:"
fibonacci "$count" "$first" "$second"
