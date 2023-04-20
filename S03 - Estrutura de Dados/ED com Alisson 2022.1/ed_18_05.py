import numpy as np

#Q1
array = []
class Pilha:

  def __init__(self, data = None, next = None):
    self.data = data
    self.next = next

#Q2 

  def pushWithClass(self, newData = None):
    if newData is None:
      return

    p1 = Pilha(self.data, self.next)

    self.data = newData
    self.next = p1

  def insertWithClass(self, Data = None):
    if Data is None:
      return

    insert = Pilha(self.data, self.next)

    self.data = insert
    self.next = self.data

  def pushWithArray (self) :
    element = self.data
    element = self.data.append()
    return element

  def insertWithArray (self) :
    x = self.data
    for x in Pilha:
      self.extend(input())
    return x
    
  
#Q3 

  def popWithclass(self):
    if not self:
      return None
    poped = self.data
    
    if self.next is None:
      self.data = None
      self.next = None

    else:
      self.data = self.next.data
      self.next = self.next.next
    return poped

  def removeWithClass (self):
    if not self:
      return None
    poped = self.next
    if self.data is None:
      self.data = None
      self.next = None
    else:
      self.next = self.data.next
      self.data = self.data.data
    return poped

  def initByArray(self, array = None):

    if array is None or len(array) == 0:
      self.data = None
      self.next = None

    else:
      self.data = array[0]
      P = Pilha()
      P.initByArray(array[1:])

    if P.data is not None:
      self.next = P
    
  def toArray(self, array=[]):
    if self is None:
      return

    array.append(self.data)

    if self.next is not None and self.next.data is not None:
      self.next.toArray(array)

    return array

#Q4

  def peek_A(self):
    peek = self.pop()
    self.push(peek)
    return peek

  
  def peek_B(self):
    return self.data

  def first_C(self):
    first = self.remove()
    filaAux = Pilha(first, None)
    filaAux.insert(self)

    while self.next is not None:
      self.remove()
      
    while filaAux.next is not None:
      f = filaAux.remove()
      self.insert(f)

    return first
    
  def first_D(self):
    return self.data

#Q5

def frameIsEmpty () :
  if len(array == 0) :
    return True
  else : 
    return False

def frameIsEmpty2 () :
  if array[0] == None :
    return True
  else : 
    return False

def frameIsEmpty3 () :
  if sum(array == None) :
    return True
  else : 
    return False

def frameIsEmpty4 () :
  if array is not None :
    array.show()
  else : 
    return print("struture is empty")

#Q6

def structureLen () :
  x = len(array)
  return x

def structureLen2 () :
  if array == None :
    return print("structure is empty")
  else:
    return len(array)

def structureLen3 () :
  myTuple = tuple(array)
  y = len(myTuple)
  return y

def structureLen4 () :
  count = 0
  for x in array :
    count += 1
  return count


#Q7

def last_A(array):
  for i in range(0, len(array)):
    if i == (len(array)-1):
        return str(array[i])

def last_B(array):
  array.reverse()
  return str(array[0])

def last_C(array):
  return str(array[len(array) -1])

def last_D(array):
  return str(array[-1])

def last_E(array):
  return str(array.pop())

def last_F(array):
  return str(next(reversed(array))

#Q8

def getValueByIndex_A(array):
  for i in range(0, len(array)) : 
    x = int(input("insert index"))
    if array == x : 
       y = array.append(i)
  return y

def getValueByIndex_B(array):
  elementindex = -1
  while True:
    try:
        elementindex = array.index(getValueByIndex_A(), elementindex+1)
        p = result.append(elementindex)
    except  ValueError:
        break

    return P

def getValueByIndex_C(array):
  return [i for i, and in enumerate(array) if and == getValueByIndex_A]

def getValueByIndex_D(array):
  return list(filter(lambda i: array[i] == , range(len(array)))

#Q9

def getIndexByValue_A(array):
  elem = int(input("enter of value"))

  try:
    index_pos = array.index(elem)
    print(f'First Index of element "{elem}" in the list : ', index_pos)
  except ValueError as e:
    print(f'Element "{elem}" not found in the list: ', e)

def getIndexByValue_B(array):
  elem = int(input("enter of value"))
  pos = -1

  for i in range(len(array)):
    if array[i] == elem:
        pos = i
        break
  if pos > -1:
    print(f'Index of element "{elem}" in the list is: ', pos)
  else:
    print(f'Element "{elem}" does not exist in the list: ', pos)

def getIndexByValue_C(array):
  elem = int(input("enter of value"))
  
  try:
    index_pos = len(larray) - array[::-1].index(elem) - 1
    print(f'Last Index of element "{elem}" in the list : ', index_pos)

  except ValueError as e:
    print(f'Element "{elem}" not found in the list: ', e)

def getIndexByValue_D(array):
  index_pos_list = []
  index_pos = 0
  while True:
      try:
        index_pos = array.index(element, index_pos)
        index_pos_list.append(index_pos)
        index_pos += 1
        except ValueError as e:
            break
  return index_pos_list

#Q10

def getAllIndexByValue_A(array):
  x = int(input("enter of value"))
  y = int(input("enter of value"))
  numpy.where(array[, x, y])

def getAllIndexByValue_B(array):
  x = int(input("enter of value"))
  y = int(input("enter of value"))
  new_tuple = (array, dtype = x, dtype = y),)

def getAllIndexByValue_C(array):
  x = int(input("enter of value"))
  y = int(input("enter of value"))
  new_array =list(zip(result[x], result[y]))

def getAllIndexByValue_Darray):
  x = int(input("enter of value"))
  y = int(input("enter of value"))
  numpy.where(array[x, y])

#Q11

def getValuesByIndexs_A (array):
    output = []
    for i in range(0, len(array)):
        if abs(array[i] - array[i-1]) > 0:
            output.append(i)
    return output

def getValuesByIndexs_B (array):
    return [i for i, (x, y) in enumerate(zip(array, array[1:]))if abs(y - x) > 0]

def getValuesByIndexs_C (array):
    output = []
    for i in range(0, len(array)):
        if abs(array[i] - array[i-1]) > 0:
            output.append(i)
    return output

def getValuesByIndexs_D (array):
  indicesList = ()
  for i in range(1, len(array)):
        if abs(array(i) - array(i-1)) > 0:
            indicesList.append(i)
  return(indicesList)

#Q12

def getValuesBySlice_A(array):
  indices = []
  value = int(input())
  idx = -1
  while True:
    try:
      idx = array.index(value, idx+1)
      indices.append(idx)
    except ValueError:
      break
  return indices

def getValuesBySlice_B(array):
  value = int(input())
  try:
    index_element = array.index(value)
    return index_element
  except ValueError:
    return None

def getValuesBySlice_C(array):
  value = int(input())
  new_array = [i for i in range(len(array)) if array[i] == value]
  return new_array

def getValuesBySlice_D(array):
  value = int(input())
  array.index(value) if value in array else None 
  new_array = [each for each in array if each == value] 
  return new_array

#Q13

def removeAll_A(array):
  for i in range(0, len(array)) :
    array.remove(i)

def removeAll_B(array):
    array.clear()

def removeAll_C(array):
  while len(array)!= 0:
    for i in range(0, len(array)) :
      array.pop(i)

def removeAll_D(array):
  del array[0:]

#Q14

def removeByIndex_A(array):
  x = int(input("index of struct))
  del array[x]

def removeByIndex_B(array):
  x = int(input("index of struct))
  array.pop(x)

def removeByIndex_C(array):
  x = int(input("index of struct))
  array.pop(x)

def removeByIndex_D(array):
  a = a[:index] + a[index+1 :]
  del array[a]

#Q17

def removeAllByIndexes_A(array):
  x = int(input("index of struct))
  del array[index([x])]
  
def removeAllByIndexes_B(array):
  st = sorted(t)
  nonzero(r_[1, diff(st)[:-1]])

def removeAllByIndexes_C(array):
  y = int(input("index of struct))
  del array[index([y])]

def removeAllByIndexes_D(array):
  l = int(input("index of struct))
  a = numpy.array(l)
  i = a.tolist().index(l)

#Q18

def removeAllBySlice_A(array):
  del array[-1]

def removeAllBySlice_B(array):
  x = int(input("index start))
  y = int(input("index end))
  del array[x:y]

def removeAllBySlice_C(array):
  x = int(input("index start))
  y = int(input("index end))
  newArray = [array - [j for i, j in enumerate(array) if i not in [x, y]]]

def removeAllBySlice_D(array):
  x = int(input("index start))
  y = int(input("index end))
  for i in sorted(indices, reverse = True):
    del array[i]

#Q19

def setValueInIndex_A (array):
  x = input("insert value))
  for i in range(len(array)):
    array[i].append()

def setValueInIndex_B (array):
  x = input("insert value)
  array[i].append(x)
  
#Q21
class Tree: 
  
  def __init__(self, data = None, left = None, right = None):
    self.data = data
    self.right = right
    self.left = left

#Q22

  def TreePreOrdem(self):
    if self.data is not None:
      print(self.data)

    if self.left is not None:
      self.left.preOrdem()

    if self.right is not None:
      self.right.preOrdem()
#Q23

  def TreeInOrdem(self):
    if self.left is not None:
      print(self.left)

    if self.data is not None:
      self.data.inOrdem()

    if self.right is not None:
      self.right.inOrdem()

#Q24

  def TreePosOrdem(self):
    if self.left is not None:
      print(self.left)

    if self.right is not None:
      self.rigth.posOrdem()

    if self.data is not None:
      self.data.posOrdem()

#Q25

  def TreeInNivel(self, array=None, ip=None):
    if self is None:
      return
    
    if ip is None or array is None:
      array = [None] * (2**self.altura() - 1)
      array[0] = self.data
      ip = 0

    if self.left is not None:
      array[2*ip + 1] = self.left.data
      self.left.completeTreeInNivel(array, 2*ip + 1)

    if self.right is not None:
      array[2*ip + 2] = self.right.data
      self.right.completeTreeInNivel(array, 2*ip + 2)
    
    return array

#Q26

  def completeTreeInNivel(self, array=None, ip=None):
    if self is None:
      return
    
    if ip is None or array is None:
      array = [None] * (2**self.altura() - 1)
      array[0] = self.data
      ip = 0

    if self.left is not None:
      array[2*ip + 1] = self.left.data
      self.left.completeTreeInNivel(array, 2*ip + 1)

    if self.right is not None:
      array[2*ip + 2] = self.right.data
      self.right.completeTreeInNivel(array, 2*ip + 2)
    
    return array
    
    def treeInNivel(self):
      array = self.completeTreeInNivel()
      array = list(filter(lambda no: no != None, array))
      return array
  
#Q27
 
  def set_root(self, key):
      self.key = key
 
      def inorder(self):
        if self.left is not None:
          self.left.inorder()
        
        if self.right is not None:
          self.right.inorder()
 
      def insert_left(self, new_node):
        self.left = new_node
 
      def insert_right(self, new_node):
        self.right = new_node
 
      def search(self, key):
        if self.key == key:
          return self

        if self.left is not None:
          temp =  self.left.search(key)
          if temp is not None:
            return temp

        if self.right is not None:
            temp =  self.right.search(key)
            return temp
        return None
 
 
      def count_nodes(self):
        if self is None:
          return 0
        return 1 + count_nodes(self.left) + count_nodes(self.right)

#Q28

  def leafNodePaths(self, data):
    paths = []
    self.dfs(data, [], paths)
      
    def dfs(self, data, current_path, paths): 
      if not data: 
        return
        
        current_path.append(root.val)
        if not root.left and not root.right:
            paths.append(current_path)
        else:
            self.dfs(root.left, current_path, paths)
            self.dfs(root.right, current_path, paths)

#Q29

  def isCompleteBT(self):
    
    if self is None:
      return True

    queue = []
    flag = False

    queue.append(self)
    while(len(queue) > 0):
        tempNode = queue.pop(0)

        if (tempNode.left):
          if flag == True :
            return False
  
          queue.append(tempNode.left)
        else:
          flag = True

        if(tempNode.right):
          if flag == True:
            return False

          queue.append(tempNode.right)
        else:
            flag = True
        
    return True
 
  if (isCompleteBT()):
    print ("Complete Binary Tree")
  else:
    print ("NOT Complete Binary Tree")

#Q30

  def isFullTree(self):

    if self is None:   
      return True

    if self.left is None and self.right is None:
      return True
 
    if self.left is not None and self.right is not None:
        return (isFullTree(self.left) and isFullTree(self.right))
     
    return False

    if isFullTree(self):
      print ("The Binary tree is full")
    else:
      print ("Binary tree is not full")

