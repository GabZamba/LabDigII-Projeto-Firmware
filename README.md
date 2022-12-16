<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-3-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

# Beam & Ball Brasil - Firmware

# Requisitos do Projeto

O projeto utiliza um ESP8266 como microcontolador por conta da sua capacidade de comunicação com a internet via Wi-Fi. Para gravar o código deste repositório no ESP8266, é necessário utilizar o [Arduino IDE](https://www.arduino.cc/en/software) como ferramenta.

# Gravando o Código no ESP8266

## Clonagem do Repositório
Para instalar o projeto, inicialmente será realizada a clonagem do repositório. Utilizando seu Terminal de Comando preferido, navegue até a pasta que contem seus projetos do Arduino IDE, como por exemplo:

```bash
cd C:\Users\Usuario\Documentos\Arduino
```

Para clonar utilizando o protocolo HTTPS, utilize o comando abaixo:

```bash
git clone https://github.com/GabZamba/LabDigII-Projeto-Firmware.git
```

Para clonar utilizando o protocolo SSH, utilize o comando abaixo:

```bash
git clone git@github.com:GabZamba/LabDigII-Projeto-Firmware.git
```

## Configuração do Arduino IDE

Para gravar o código utilizando o Arduino IDE, é necessário adicionar a placa ESP8266 ao gerenciador de placas. Para isso, siga os passos abaixo:

### Etapa 1: Adicionar a URL do Gerenciador de Placas

Abra o Arduino IDE e vá em **Arquivo > Preferências**. No campo **URLs Adicionais de Gerenciadores de Placas**, cole a URL abaixo e clique em OK.

```bash
https://arduino.esp8266.com/stable/package_esp8266com_index.json
```

### Etapa 2: Instalar a Placa ESP8266

Vá em **Ferramentas > Placa > Gerenciador de Placas**. Procure por **esp8266** e instale a versão mais recente.

### Etapa 3: Selecionar a Placa ESP8266

Vá em **Ferramentas > Placa** e selecione a placa **NodeMCU 1.0 (ESP-12E Module)**.

### Etapa 4: Instalar as Bibliotecas

Para instalar as bibliotecas necessárias, vá em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**. Procure por **PubSubClient** e instale a versão mais recente.

### Etapa 5: Selecionar a Porta de Comunicação

Com o ESP8266 já conctado no seu computador através do USB, para selecionar a porta de comunicação, vá em **Ferramentas > Porta** e selecione a porta que está conectada à placa.

### Etapa 6: Gravar o Código

Para gravar o código no ESP8266, clique em **Verificar** e em seguida em **Gravar**.


*PARABÉNS, VOCÊ CONSEGUIU RODAR O PROJETO 🎉🎉🎉*


# Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tbody>
    <tr>
      <td align="center"><a href="https://github.com/GabZamba"><img src="https://avatars.githubusercontent.com/u/98465378?v=4?s=100" width="100px;" alt="Gabriel Zambelli"/><br /><sub><b>Gabriel Zambelli</b></sub></a><br /><a href="https://github.com/PedroDeSanti/FlightOps/commits?author=GabZamba" title="Code">💻</a> <a href="https://github.com/PedroDeSanti/FlightOps/commits?author=GabZamba" title="Documentation">📖</a></td>
      <td align="center"><a href="https://github.com/jvtdegelo"><img src="https://avatars.githubusercontent.com/u/64590453?v=4?s=100" width="100px;" alt="jvtdegelo"/><br /><sub><b>jvtdegelo</b></sub></a><br /><a href="https://github.com/PedroDeSanti/FlightOps/commits?author=jvtdegelo" title="Code">💻</a> <a href="https://github.com/PedroDeSanti/FlightOps/commits?author=jvtdegelo" title="Documentation">📖</a></td>
      <td align="center"><a href="https://github.com/PedroDeSanti"><img src="https://avatars.githubusercontent.com/u/62271285?v=4?s=100" width="100px;" alt="Pedro de Santi"/><br /><sub><b>Pedro de Santi</b></sub></a><br /><a href="https://github.com/PedroDeSanti/FlightOps/commits?author=PedroDeSanti" title="Code">💻</a> <a href="https://github.com/PedroDeSanti/FlightOps/commits?author=PedroDeSanti" title="Documentation">📖</a></td>
    </tr>
  </tbody>
  <tfoot>
    
  </tfoot>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!

