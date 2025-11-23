![Logo](logo.png)
# Lince - Módulo de Sensores IoT (ESP32 + MQTT + Node-RED)

Este módulo faz parte do ecossistema **Lince** e é responsável pela leitura e transmissão dos dados de temperatura e umidade do ambiente de trabalho utilizando sensores acoplados ao **ESP32**, enviando-os via **MQTT** para o fluxo do **Node-RED**, que por sua vez redireciona os dados para APIs, dashboards ou sistemas de análise.

# Sobre o Lince 

O Lince é um sistema completo para monitoramento, análise e gestão
de EPIs (Equipamentos de Proteção Individual), integrando dados em
tempo real de sensores instalados em estações e ambientes operacionais.
A plataforma permite acompanhar uso, conformidade, alertas de segurança,
condições ambientais e comportamento operacional, garantindo maior
proteção para colaboradores e maior controle para equipes de supervisão
e segurança.

Além do monitoramento de EPIs, o sistema também realiza medições de
temperatura e umidade do ambiente de trabalho, permitindo identificar
condições inadequadas que possam gerar riscos de acidentes, como
sobreaquecimento, umidade excessiva, falhas elétricas ou ambientes
inseguros para a operação.

Nosso objetivo é oferecer uma solução moderna e confiável para
monitoramento inteligente de EPIs e condições ambientais, reduzindo
riscos, prevenindo acidentes e centralizando informações essenciais para
os times de segurança corporativa.

## Problemas que a aplicação resolve
-   Falta de visibilidade sobre **uso correto** de EPIs.
-   Dificuldade em monitorar automaticamente **violação de áreas
    restritas**.
-   Baixa eficiência em auditorias e checklists de segurança.
-   Falta de relatórios centralizados para tomada de decisão.
-   Integração limitada entre sensores físicos e aplicações
    administrativas.
-   Falta de controle sobre temperatura e umidade do ambiente, podendo levar a
    superaquecimento de máquinas, desconforto térmico e situações que aumentam
    o risco de acidentes.

## Sobre o time

- **Arthur Algate RM:560109**: Responsável pelo banco de dados e Compliance QA.  
- **Carlos Clementino RM:561187**: Responsável pelo desenvolvimento da API em Java Spring Boot e .NET, infraestrutura e práticas de DevOps, integração com dispositivos IoT.  
- **Eder Silva RM:559647**: Responsável pela criação do APP mobile.

## Descrição Geral

Este repositório inclui:

- Código em **C++** para ESP32
- Comunicação MQTT com broker local ou remoto
- Fluxo Node-RED integrado
- Dashboard para visualização em tempo real

A leitura de temperatura e umidade é feita por sensores conectados ao ESP32, que publica os dados em tópicos MQTT específicos. O Node-RED consome esses tópicos, processa os valores e envia para o backend ou exibe diretamente em dashboards.

---

## Arquitetura

```
[Sensores] -> [ESP32] -> [MQTT Broker] -> [Node-RED] -> [Dashboard / API]
```

---

## Funcionalidades

- Leitura contínua de sensores analógicos
- Conexão Wi-Fi integrada via ESP32
- Publicação MQTT com intervalo configurável
- Fluxos automáticos do Node-RED para tratamento de dados
- Dashboard real-time

---

## Requisitos

### Hardware
- ESP32 (DevKit, WROOM ou similar)
- Sensor de temperatura (LM35, DS18B20, TMP36, etc.)
- Sensor de umidade (DHT11, DHT22, SHT20, etc.)
- Cabos jumper e protoboard

### Software
- Arduino IDE ou PlatformIO
- Biblioteca PubSubClient
- Node-RED instalado
- Broker MQTT

---

## Link do vídeo demonstrando o funcionamento
[Assista agora](https://youtu.be/pvMbEKtmw2Q)

---

## Código ESP32 (C++)

O funcionamento do sistema ocorre da seguinte forma: o ESP32 conecta à rede Wi-Fi e, em seguida, se conecta ao broker MQTT. Após isso, ele simula dados de sensores, constrói um JSON com as informações e publica os dados no tópico MQTT configurado. Esse processo é repetido continuamente.

---

## Fluxo Node-RED

O fluxo deve incluir:

- Nó de entrada MQTT (subscribe em `sensor/control`)
- Nó function para converter dados brutos
- Nó de saída (API, dashboard ou banco de dados)

O fluxo em JSON será incluído no repositório.

---

## Dashboard

O dashboard inclui:

- Indicadores em tempo real (temperatura, umidade)
- Informações do sensor
- Status do sistema

Pode ser acessado via navegador após iniciar o live server do dashboard.

---

## Como rodar os serviços

1. Inicie o **Node-RED** localmente em sua máquina (`node-red` no terminal) e importe o fluxo disponível no repositório.
2. Configure o broker MQTT conforme indicado no fluxo.
3. Conecte o **ESP32** à rede Wi-Fi para iniciar o envio dos dados.
4. Abra o **VS Code** e acesse a pasta do repositório.
5. Abra o arquivo `index.html` e inicie o **Live Server** para visualizar os dados em tempo real.

---

## Estrutura do Repositório

```
/
   |- fluxo-node.json
   |- codigo-fonte.ino
   |- index.html
```

---

**Lince** — Visão total. Risco mínimo. 🦁

