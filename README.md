# CGEngie
## 개요
미니  CLI MVC 프로젝트다. 콘솔의 CLI를 페이지 단위로 구분해서 병렬적으로 개발 할 수 있게 도와주는 프레임워크다. 

## 장점
while을 활용한 무한 대기 메커니즘이 아닌 스레드 생성/삭제 메커니즘으로 두가지 장점을 얻었다.  

1. **메모리 최적화** : while에서 계속해서 페이지 전환이 일어나면, 스택에 함수 문맥이 쌓이게 되고, 메모리오버플로우가 발생할 위험이 있다. 해당 에러방지 및 메모리 최적화를 위해 페이지를 열 때 페이지 
스레드를 생성해서 사용한다. 페이지 전환이 일어날 때 해당 페이지 스레드를 삭제하고, 다음 페이지 스레드를 실행한다. 스택에 함수 문맥이 쌓이는 것을 방지하고, 적은 메모리 사용으로 가용성을 높인다.

2. **결합도 낮음** : while의 무한 반복 구조와 각 페이지의 결합도가 매우 높다. 반복중 if로 해당되는 페이지를 실행해야하기 때문이다. 스레드 생성/삭제 메커니즘으로 인해 하나의 페이지는 하나의 스레드로 
처리된다. 각 페이지(스레드)가 다른 페이지(스레드)를 실행할 수 있는 구조로 페이지는 각각 독립성을 가지고, 필요 시에 데이터만 전달 한다.
