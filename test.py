import build  # Импортируем скрипт сборки

# Теперь можно использовать indexed_map после сборки
import indexed_map

def main():

    # Создаем объект IndexedMap
    imap = indexed_map.IndexedMap()

    # Вставляем значения
    imap.insert("one", 1)
    imap.insert("two", 2)
    imap.insert("three", 3)

    # Поиск значения
    found, value = imap.find("two")
    if found:
        print(f"Found value: {value}")
    else:
        print("Key not found.")

    # Проверка на наличие ключа
    print(imap.contains("two"))  # True
    print(imap.contains("four"))  # False

    # Удаление ключа
    # imap.remove("two")
    # print("After removing key 2:")
    # imap.print()

    # Получение ключа по индексу
    try:
        print(f"Key at index 0: {imap.get_key_by_index(0)}")
    except Exception as e:
        print(e)

    # Доступ к значению по индексу
    try:
        print(f"Value at index 0: {imap['zero']}")
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()
