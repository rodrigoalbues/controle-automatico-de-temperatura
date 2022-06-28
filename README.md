# controle-automatico-de-temperatura
 Sistema para Controle automático de temperatura utilizando arduíno.
 
 Este trabalho foi desenvolvido na disciplina Sensores, Atuadores e Interfaces de Comunicação, durante a Especialização em Internet das Coisas (IoT).

Foi desenvolvido um sistema para controlar a temperatura de um motor de produção de forma automatizada utilizando um sensor de temperatura e o arduino uno .

Por meio de um botão o sistema é ligado. Com o sistema ligado, se a temperatura for igual ou menor que 30°C, o motor de produção é acionado. A temperatura chegando à 40°C é acionado um ventilador para o resfriamento em uma velocidade inicial. Com 60°C esse ventilador passa para um segundo nível com uma velocidade maior e alcançando uma temperatura igual ou maior à 80°C o ventilador vai para o terceiro e último nível com a velocidade máxima. Com 90°C o motor de produção é desligado automaticamente. E o ventilador desliga quando a temperatura estiver abaixo de 40°C.
