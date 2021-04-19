# CloudWalk Software Enginner Test

This project aims solve a Test to Software Engineering positions at CloudWalk.

It's composed by a parser which reads Quake 3 Arena log and groups game data of the matches.
In addition, a script was developed to collect game data and show it readable on screen.

## Dependencies

#### CMake 
[CMake](https://cmake.org/) was used to manage the build process. That way we can easily change the compiler and the operating system without further reworks.

Installation suggestion:
```bash
    sudo apt-get install cmake
```

#### googletest
The [googletest](https://github.com/google/googletest) was the framework chosen to orchestrate the unit test due developer's prior knowledge.

Installation suggestion:
```bash
    sudo apt-get install googletest
```

## Getting started

To reproduce the environment get the source code:
```bash
    git clone https://gitlab.com/albmiranda/logparser.git
    cd logparser
```

Now you are ready to compile the code:
```bash
    mkdir build
    cd build

    # choose the build type
    cmake ../ ## for release build - this option make all warnings into errors and turns on all optimizations
    #or
    cmake -DCMAKE_BUILD_TYPE=Debug ../ ## for debug build - this options shows debug information on compile time and include symbols into the binary.

    make -j4
    make install
```

## Usage
Once you get started application binary will be delivered to \${PROJECT_ROOT}/bin as **logparser**.
```bash
   ./bin/logparser
```
Run it and a file match.rec whithin \${PROJECT_ROOT}/out will be created to store the game data. Later that file is use by a script to summarize the game data.

#### Memory Leak detection

This project aims to free all heap blocks. To achieve it the valgring was used. To validate results type:
```bash
   valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./bin/logparser
```

## Tests

To provide more confidence the source code was submitted to unit test.
A unit test application will be available after regular [compile](#getting-started) as well, to run it just type:.
```bash
   ctest --verbose
```

Para maior confiabilidade e identificação precoce de eventuais falhas do código, foram elaborados testes unitários no core da aplicação, i.e., no pacote responsável por encontrar a posição da nave e, também, que decrifra a mensagem recebida.

Para execução dos testes e conseguinte análise de cobertura do código faça:
```shell
make test
```

Exemplo de saída:
```
andre@laptop:~/go/src/go-meli$ make test

Test and coverage
go test -coverpkg=./... -coverprofile=profile.cov ./...
?   	go-meli/cmd/main	[no test files]
?   	go-meli/internal/db	[no test files]
?   	go-meli/internal/handler	[no test files]
?   	go-meli/internal/http	[no test files]
ok  	go-meli/internal/satellite	0.015s	

coverage: 19.1% of statements in ./...
?   	go-meli/pkg/dynamodb	[no test files]
go tool cover -func profile.cov
go-meli/cmd/main/main.go:12:				handlers				0.0%
go-meli/cmd/main/main.go:38:				main					0.0%
go-meli/internal/db/db.go:10:				GetAllSatellites			0.0%
go-meli/internal/db/db.go:26:				UpdateSingleSatellite			0.0%
go-meli/internal/db/db.go:38:				UpdateMultipleSatellites		0.0%
go-meli/internal/handler/GetShipData.go:16:		GetShipData				0.0%
go-meli/internal/handler/PostMultipleSatellites.go:17:	PostMultipleSatellites			0.0%
go-meli/internal/handler/PostSingleSatellite.go:17:	PostSingleSatellite			0.0%
go-meli/internal/http/http.go:19:			ClientError				0.0%
go-meli/internal/satellite/findShip.go:9:		FindShip				0.0%
go-meli/internal/satellite/location.go:19:		round					100.0%
go-meli/internal/satellite/location.go:23:		toFixed					100.0%
go-meli/internal/satellite/location.go:28:		calculateThreeCircleIntersection	75.8%
go-meli/internal/satellite/location.go:108:		GetLocation				0.0%
go-meli/internal/satellite/message.go:8:		deleteElementFromArray			100.0%
go-meli/internal/satellite/message.go:16:		deleteEmptyWord				100.0%
go-meli/internal/satellite/message.go:31:		deletePreviousWord			0.0%
go-meli/internal/satellite/message.go:50:		deleteDuplicatedWord			0.0%
go-meli/internal/satellite/message.go:63:		GetMessage				0.0%
go-meli/pkg/dynamodb/dynamodb.go:19:			Scan					0.0%
go-meli/pkg/dynamodb/dynamodb.go:29:			GetItemSatellite			0.0%
go-meli/pkg/dynamodb/dynamodb.go:41:			NewItem					0.0%
go-meli/pkg/dynamodb/dynamodb.go:56:			PutItem					0.0%
total:							(statements)				19.1%
```

## Pipeline 

O projeto também contempla pipeline de integração contínua. Para ter acesso basta qualquer commit em branches develop, main e feature/.

## Backlog de evolução

Apesar do projeto atender o objetivo proposto há diversas possibilidades de melhoria para serem feitas com o investimento de mais horas de desenvolvimento.

Destas melhorias, particularmente, eu, atuaria em frentes para garantir melhor resultado na entrega, tais como:
* Aumento da cobertura de testes unitários
* Testes regressivos com mocks
* Pipeline de CD



# obrigado


