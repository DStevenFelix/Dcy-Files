

import operator
from numpy import log
import matplotlib.pyplot as plt
def createTree(dataSet,labels):
    classList = [example[-1] for example in dataSet]
    if classList.count(classList[0]) == len(classList):
        return classList[0]
    if len(dataSet[0]) == 1:
        return majorityCnt(classList)
    bestFeat = chooseBestFeatureToSplit(dataSet)
    bestFeatLabel = labels[bestFeat]
    myTree = {bestFeatLabel:{}}
    del(labels[bestFeat])
    featValues = [example[bestFeat] for example in dataSet]
    uniqueVals = set(featValues)
    for value in uniqueVals:
        subLabels = labels[:]
        myTree[bestFeatLabel][value] = createTree(splitDataSet(dataSet, bestFeat, value),subLabels)
    return myTree

#计算当前类别中数量最多的
def majorityCnt(classList):
    classCount={}
    for vote in classList:
        if vote not in classCount.keys():
            classCount[vote]=0.0
        classCount[vote]+=1
    #进行排序操作
    sortedclassCount=sorted(classCount.items(),key=operator.itemgetter(1),reverse=True)
    return sortedclassCount[0][0] #返回出现次数最多的情况

#选择最好的特征作为根节点
def chooseBestFeatureToSplit(dataset):
    numFeatures=len(dataset[0])-1
    baseEntropy=calcShannonEnt(dataset)
    bestInfofGain=0.0 #最好的熵值
    bestFeature=-1
    for i in range(numFeatures):
        featList=[example[i] for example in dataset]
        uniqueValues=set(featList)
        newEntropy=0.0
        for val in uniqueValues:
            subDataSet=splitDataSet(dataset,i,val)
            prob=len(subDataSet)/float(len(dataset))
            newEntropy+=prob*calcShannonEnt(subDataSet)
        #计算信息增益
        infoGain=baseEntropy-newEntropy
        if infoGain>bestInfofGain:
            bestInfofGain=infoGain
            bestFeature=i
    return bestFeature

def splitDataSet(dataset,axis,val):
    retDataSet=[]
    for featVec in dataset:
        if featVec[axis]==val:
            reducedFeatVec=featVec[:axis]
            #extend方法是Python列表的一个方法，它的作用是在列表的末尾一次性追加另一个可迭代对象中的多个元素（用新列表扩展原来的列表）
            reducedFeatVec.extend(featVec[axis+1:])
            retDataSet.append(reducedFeatVec)
    return retDataSet  #返回数切分集

#首先需要计算基础的熵值
def calcShannonEnt(dataset):
    numexamples=len(dataset) #计算出总样本个数
    labelCounts={} #使用字典进行存储
    for featVec in dataset:
        currentlabel=featVec[-1]
        if currentlabel not in labelCounts.keys():  #分别统计出yes和no的个数
            labelCounts[currentlabel]=0
        labelCounts[currentlabel]+=1 #如果在当前这个字典中则进行增加操作
    shannonEnt=0.0
    for key in labelCounts:
        prop=float(labelCounts[key])/numexamples #计算概率值
        shannonEnt-=prop*log(prop) #计算熵值 pandas中的log一般是以2为底
    return shannonEnt  #返回熵值

#绘画决策树

decisionNode = dict(boxstyle="round4", fc="yellow") #设置根节点的形状和颜色(熵值最大的位置为根节点)
leafNode = dict(boxstyle="circle", fc="green")      #设置叶子节点的形状和颜色(标签位置)
arrow_args = dict(arrowstyle="<-")                  #设置连接符号


def getNumLeafs(myTree):
    numLeafs = 0
    firstStr = list(myTree.keys())[0]
    secondDict = myTree[firstStr]
    for key in secondDict.keys():
        if type(secondDict[key]).__name__=='dict':
            numLeafs += getNumLeafs(secondDict[key])
        else:   numLeafs +=1
    return numLeafs

def getTreeDepth(myTree):
    maxDepth = 0
    firstStr = list(myTree.keys())[0]
    secondDict = myTree[firstStr]
    for key in secondDict.keys():
        if type(secondDict[key]).__name__=='dict':
            thisDepth = 1 + getTreeDepth(secondDict[key])
        else:   thisDepth = 1
        if thisDepth > maxDepth: maxDepth = thisDepth
    return maxDepth

def plotNode(nodeTxt, centerPt, parentPt, nodeType):
    createPlot.ax1.annotate(nodeTxt, xy=parentPt,  xycoords='axes fraction',
             xytext=centerPt, textcoords='axes fraction',
             va="center", ha="center", bbox=nodeType, arrowprops=arrow_args )

def plotMidText(cntrPt, parentPt, txtString):
    xMid = (parentPt[0]-cntrPt[0])/2.0 + cntrPt[0]
    yMid = (parentPt[1]-cntrPt[1])/2.0 + cntrPt[1]
    createPlot.ax1.text(xMid, yMid, txtString, va="center", ha="center", rotation=30)

def plotTree(myTree, parentPt, nodeTxt):
    numLeafs = getNumLeafs(myTree)
    depth = getTreeDepth(myTree)
    firstStr = list(myTree.keys())[0]
    cntrPt = (plotTree.xOff + (1.0 + float(numLeafs))/2.0/plotTree.totalW, plotTree.yOff)
    plotMidText(cntrPt, parentPt, nodeTxt)
    plotNode(firstStr, cntrPt, parentPt, decisionNode)
    secondDict = myTree[firstStr]
    plotTree.yOff = plotTree.yOff - 1.0/plotTree.totalD
    for key in secondDict.keys():
        if type(secondDict[key]).__name__=='dict':
            plotTree(secondDict[key],cntrPt,str(key))
        else:
            plotTree.xOff = plotTree.xOff + 1.0/plotTree.totalW
            plotNode(secondDict[key], (plotTree.xOff, plotTree.yOff), cntrPt, leafNode)
            plotMidText((plotTree.xOff, plotTree.yOff), cntrPt, str(key))
    plotTree.yOff = plotTree.yOff + 1.0/plotTree.totalD

def createPlot(inTree):
    fig = plt.figure(1, facecolor='white')
    fig.clf()
    axprops = dict(xticks=[], yticks=[])
    createPlot.ax1 = plt.subplot(111, frameon=False, **axprops)
    plotTree.totalW = float(getNumLeafs(inTree))
    plotTree.totalD = float(getTreeDepth(inTree))
    plotTree.xOff = -0.5/plotTree.totalW; plotTree.yOff = 1.0
    plotTree(inTree, (0.5,1.0), '')
    plt.show()

#传入数据集
dataset=[['1', '1', '3', 'French', 'Someone', '0-10', 'yes'],
['1', '1', '1', 'Chinese', 'Full', '30-60', 'no'],
['0', '0', '1', 'Fast', 'Someone', '0-10', 'yes'],
['1', '1', '1', 'Chinese', 'Full', '10-30', 'yes'],
['1', '0', '3', 'French', 'Full', '>60', 'no'],
['0 ', '1', '2', 'Italian', 'Someone', '0-10', 'yes'],
['0', '0', '1', 'Fast', 'Nobody', '0-10', 'no'],
['0', '1', '2', 'Chinese', 'Someone', '0-10', 'yes'],
['0', '0', '1', 'Fast', 'Full', '>60', 'no'],
['1', '1', '3', 'Italian', 'Full', '10-30', 'no'],
['1', '0', '1', 'Fast', 'Nobody', '0-10', 'no'],
['0', '1', '1', 'Fast', 'Full', '30-60', 'yes']]
# print(dataset) 测试数据集合是否正确
#定义标签
labels=['choices','hungry','price','type','numbers','waiting_time']
tree=createTree(dataset,labels)
createPlot(tree)