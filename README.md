# Descrição Trabalho Final Algoritmos
Trabalho final da disciplina de algoritmos - IFC

>>> Problema 2: Cálculo do PI <<<

O valor do PI pode ser calculado de várias maneiras, sendo que uma delas é utilizando o método de aproximação do PI proposto por Monte Carlo que pode ser visto abaixo:
* Dado um círculo com raio r (em radianos) em um quadrado com tamanho de 2r
* A área do círculo é Πr² e a área do quadrado é 4r²
* A relação entre a área do círculo e a área do quadrado é: Πr2 / 4r2 = Π / 4
* Se for gerado aleatoriamente N pontos dentro do quadrado, aproximadamente N * Π / 4 destes pontos (M) devem cair dentro do círculo.
* Assim, o valor do PI (Π) é então aproximado como: 
  N * Π / 4 = M 
  Π / 4 = M / N 
  Π = 4 * M / N
* Observe que quanto mais cresce o número de pontos gerados mais a aproximação do PI aumenta.


Exemplo de código sequencial
------------------------------------------------------
npoints = 10000
circle_count = 0

do j = 1,npoints
      generate 2 random numbers between 0 and 1
      xcoordinate = random1
      ycoordinate = random2
      if (xcoordinate, ycoordinate) inside circle
      then circle_count = circle_count + 1
end do

PI = 4.0*circle_count/npoints
------------------------------------------------------
