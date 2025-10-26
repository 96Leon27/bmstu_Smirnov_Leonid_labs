#!/bin/bash

dir="$1"
remote_server="sadmarnai.ru"  # адрес сервера
port="3721"                  # порт сервера

# Если директории нет – создаем
if [ ! -d "$dir" ]; then
    mkdir -p "$diry"
fi

# Создание файлов директории и запись номеров в них
for i in {1..5}; do
    filename="$dir/file$i.txt"
    echo "$i" > "$filename"
done

# Отправляем файлы
cat "$directory"/*.txt | nc "$remote_server" "$port"


# Проверяем статус завершения netcat
nc_exit_code=$?

if [ $nc_exit_code -eq 0 ]; then
    echo "Данные отправлены."
else
    echo "Ошибка во всермя исполнения"
    exit 1
fi

echo "Скрипт завершён успешно!"
