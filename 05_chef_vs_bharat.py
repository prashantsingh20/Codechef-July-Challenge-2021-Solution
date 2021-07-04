class PalindromeAndPrefixSumEncapsulated:
  def __init__(self, n):
    self.n = n
    self.i = 0
    self.palindromes = [0]*n
    self.prefixSums = [0]*n
    
  def add(self, val):
    self.palindromes[self.i] = val
    self.prefixSums[self.i] = val
    if self.i != 0:
      self.prefixSums[self.i] += self.prefixSums[self.i-1]
    self.i = self.i+1
    
  def isFull(self):
    return self.i == self.n
        
  def getPrefixSumInRange(self, L, R):
    return self.prefixSums[R]-self.prefixSums[L]
        
  def getFirstPalin(self, index):
    return self.palindromes[index]

      
def createOddPalin(inp):
  n = inp
  palin = inp
  n = n//10
  while n > 0:
    palin = palin*10+(n%10)
    n = n//10
  return palin;


def generatePalindromes(palindromeAndPrefixSumEncapsulated):
  i = 1
  while not palindromeAndPrefixSumEncapsulated.isFull():
    palindromeAndPrefixSumEncapsulated.add(createOddPalin(i))
    i = i+1
    

def solve(L, R, palindromeAndPrefixSumEncapsulated):
    power = palindromeAndPrefixSumEncapsulated.getPrefixSumInRange(L-1, R-1);
    base = palindromeAndPrefixSumEncapsulated.getFirstPalin(L-1);
    return pow(base, power, 1000000007);

palindromeAndPrefixSumEncapsulated = PalindromeAndPrefixSumEncapsulated(100001)
generatePalindromes(palindromeAndPrefixSumEncapsulated)
q = int(input())
while q > 0:
    q = q-1
    line = input().split(" ")
    L, R = int(line[0]), int(line[1])
    print(solve(L, R, palindromeAndPrefixSumEncapsulated))