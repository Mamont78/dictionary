#pragma once

int check_record( struct Word * );                     //проверка записи слова
void normalization( struct Word * );                    //нормализация слова. Перевод с верхнего регистра в нижний
int control_lengths( struct Word * );					//проверка длины слова
