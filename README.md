# dos_detection using machine learning algorithms
Kddcup data set used.
7 symbolic data features used to develop the Naive Bayes classifier.
Used 34 numeric features of the tcp-ip network as obtained from the kdd cup dataset , to develop the Logistic classifier

List of files:

setupData.py -> Used to extract only those rows from the csv files which correspond to normal traffic or dos-infected traffic

To run:
	python setupData.py trainData.csv train_set.csv

setupDataNB.sh -> Used to extract only columns/features 2,3,4,7,11,20,21 and 42 i.e. the ones which contain the symbolic values 

To run:
	bash setupDataNB.sh train_set.csv trainNB_set.csv

setupDataLR.sh -> Used to extract those columns/features that contain numeric values

To run:
	bash setupDataLR.sh train_set.csv trainLR_set.csv

nbClassifier.cpp -> Used for performing the classification using Naive Bayes algorithm. Both traing and testing done in same file.

To run:
	g++ nbClassifier.cpp
	./a.out trainNB_set.csv testNB_set.csv

logitClassifier.r -> Used for performing the classification using Logistic Regression. Both traing and testing done in same file.
Traing data file and testing data file mentioned inside the classifier file.

To run:
	r logitClassifier.r 
