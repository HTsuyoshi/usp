import numpy as np

if __name__ == '__main__':
    data = np.genfromtxt('./chicago-public-schools-progress-report-cards-2011-2012-1.csv', delimiter=',', dtype=str)
    print(len(data[0]))
    #for category in data[0]:
    #    print(category)
