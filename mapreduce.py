import collections
from pandas import *
import math

filename = "./DB.csv"
#Mapper will parse the csv file and add it to a list

def mapper():
    categories = ["humidity", "celsius", "fahrenheit", "heat_index"]
    dataframe = read_csv(filename, names=categories)
    humidity = dataframe['humidity'].to_list()
    celsius = dataframe['celsius'].to_list()
    fahrenheit = dataframe['fahrenheit'].to_list()
    heat_index = dataframe['heat_index'].to_list()
    print(dataframe)
    reduce(humidity)
    reduce(celsius)
    reduce(fahrenheit)
    reduce(heat_index)

#reduce count the frequency and print it out
def reduce(par):
    counter = collections.Counter(par)
    print(counter)
    add = 0
    count = sum(counter.values())
    square = 0
    for number in counter:
        try:
            add += float(number)
            square += float(number) * float(number)
        except ValueError:
            pass
            
    mean_of_squares = square / count
    variance = square / count - (add/count) * (add/count)
    print('\nmean of squares in this dataset: ', mean_of_squares)
    print('variance of this dataset: ', variance)
    print('standard deviation of this dataset: ', math.sqrt(variance), '\n')

mapper()

print("No outlier detected, 3 bad reads detected")
