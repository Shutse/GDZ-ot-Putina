factorial() {
  local num=$1
  local result=1

  if [[ ! "$num" =~ ^[0-9]+$ ]]; then
    echo "Ошибка: Введите целое неотрицательное число."
    return 1
  fi

  if (( num < 0 )); then
    echo "Ошибка: Факториал отрицательного числа не определен."
    return 1
  fi

  if (( num > 20 )); then
    echo "Ошибка: Слишком большое число. Факториал будет очень большим."
    return 1
  fi

  for ((i=1; i<=num; i++)); do
    result=$((result * i))
  done

  echo "$result"
}

read -p "Введите целое неотрицательное число: " input

result=$(factorial "$input")

if [[ $? -eq 0 ]]; then
  echo "Факториал числа $input равен $result"
else
  echo "Вычисление факториала не удалось."
fi
