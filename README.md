# Задание 6: Калькулятор полиномов
Реализовать класс, который реализует возможность выполнения операций сложения, вычетания, умножения, взятие производной и интеграла над полиномами n-го порядка с целыми коэффициентами, заданными в [польской нотации](https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D0%BB%D1%8C%D1%81%D0%BA%D0%B0%D1%8F_%D0%B7%D0%B0%D0%BF%D0%B8%D1%81%D1%8C).
Программа должна работать как "калькулятор" полиномов, пользователь вводит необходимые операции в командной строке в польской нотации и получает ответ в польской нотации.
## Входные данные:
Пользователь вводит необходимый набор операций в коммандную строку.
Доступные операции:
```
+
-
*
der // derivative
int // integral
```
Пример 
```
Please enter your expression:
der * + [1 2 3] [4 5] [6 7] 
```
Пример для интеграла
```
Please enter your expression:
int + [1 2 3] [4 5] 
```


Числа в квадратных скобках представляют собой коэффициеты полинома по возрастающим степеням.
```
[4 8 3]
Соответствует полиному
4 + 8*x + 3*x^2