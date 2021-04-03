# 모니터링이란? , 모니터링의 필요성

    * 특정 소프트웨어를 운영하게 되면 장애가 발생할 가능성은 항상 존재함

    * 시스템의 상태를 명확하게 파악하기 어렵다면 장애를 미리 방지할 수 없을 뿐 아니라 장해가 발생했을 때에 원인을 찾는 것도 어려울 것임

    * 모니터링 서버를 잘 구축해 두면 시스템의 상태를 명확히 인지할 수 있을 것이고 이를 바탕으로 여러 직관을 얻을 수 있고 이를 통해 장애에 대한 예측, 대응이 가능할 것임

    * 따라서 모니터링이 필요함

    * ex> 특정 서버의 부하가 특정 시간에 높아지는 것을 인지하여 그 시간에만 리소스 확장
    * ex> network traffic이 일정 시간동안 일정 비율로 꾸준히 높아지게 되면 경고 알람 전송

    * 모니터링을 위한 오픈소스 중 Prometheus를 살펴볼 것임
    * Demo와 개념 설명을 같이 진행

# 목차
    0.  대략적인 설명(아키텍처)
    1.  exporter example
    2.  Pushgateway(x)
    3.  Prometheus 
        1.  Service Discovery  
        2.  PromQL
    4.  alert
        1. prometheus 내부에 정의된 rule
        2. alertmanager
    5. Grafana


# 실습 환경 갖추기

0.  prometheus와 node_exporter는 이미 ec2에 올려둠 => 로컬에서 그라파나만 설치해서 보면서 하면 됨

1.  링크(https://grafana.com/grafana/download?platform=windows)로 들어가서 grafana window버전 다운로드

![image](https://user-images.githubusercontent.com/41561652/113390419-a4a7bd80-93cc-11eb-90b8-0aa8b73f744c.png)

2.  로그인(최초: admin / admin)
3.  datasource 설정(이때 EC2에 노출시킨 prometheus서버에 붙어야 함)

![image](https://user-images.githubusercontent.com/41561652/113390475-c143f580-93cc-11eb-8e4a-5a70c3452753.png)

4.  node_exporter_full을 import(https://grafana.com/grafana/dashboards/1860)

# 본론
0.  대략적인 설명(아키텍처)

![image](https://user-images.githubusercontent.com/41561652/113249662-09461800-92fa-11eb-8877-de69771aec08.png)

1.  Exporter

    0. 기본적으로 collector들을 등록해 주면 해당 메트릭을 수집해서 HTTP GET endpoint를 제공하는 방식
        * collector는 설정을 통해 추가 및 제거 가능
        * exporter는 http endpoint를 제공하고 이를 prometheus에서 pulling 하는 방식임
        * https endpoint는 실험적으로 제공하고 있음

    1. exporter example
        * https://github.com/prometheus
        * https://github.com/prometheus-community
        * 대표적인 exporter: node_exporter(linux) & spring boot actuator
            * node exporter
                * linux hw 및 os 자원 메트릭 제공
                * MyDemo: http://localhost:3000/d/Hoc62F_Mz/ec2-resource-usage-copy?orgId=1
                * import: http://localhost:3000/d/rYdddlPWk/node-exporter-full?orgId=1&refresh=1m

            * spring boot actuator
                * Actuator는 Spring MVC 혹은 Spring WebFlux를 사용하는 경우, Micrometer를 통해 생성된 애플리케이션의 metric을 Prometheus 서버에서 가져갈(Pull)수 있도록 추가적인 endpoint를 제공해준다.
                * ![image](https://user-images.githubusercontent.com/41561652/113250764-1401ac80-92fc-11eb-9115-962df9e14b3f.png)
                * 실제로는 애플리케이션에서 기본적으로 제공하는 Metric 뿐만 아니라 Micrometer를 이용해 직접 필요한 Metric을 추가할 수도 있다.
                * import: http://localhost:3000/d/y6AL2FlMk/jvm-micrometer?orgId=1&refresh=30s


2.  Pushgateway(x)

3.  Prometheus

    0.  기본 설정파일 example
    
    ![image](https://user-images.githubusercontent.com/41561652/113258442-e8d08a80-9306-11eb-8b05-c567786671bb.png)

        
    1.  Service Discovery  
        * prometheus에서 모니터링 대상이 되는 외부 시스템에 대한 endpoint를 정의한 파일
        * 이 파일에 정의된 endpoint 에서 메트릭을 수집

    2.  PromQL
        * prometheus는 수집된 메트릭 데이터를 시계열로 DB에 저장하는데, 이 데이터를 원하는 형태로 조회하기 위해 사용하는 Qeury Language
        * EX> http://localhost:3000/d/Hoc62F_Mz/ec2-resource-usage-copy?orgId=1
        
            ## instance vector, range vector
            *  ![image](https://user-images.githubusercontent.com/41561652/113255271-98572e00-9302-11eb-8748-d826d961fead.png)

            ## CPU Utilization
            ![image](https://user-images.githubusercontent.com/41561652/113255336-ac029480-9302-11eb-8456-6ebb2ae7d82d.png)
            * CPU 사용량을 1을 기준으로 한 비율로 모드 별로 표현한 그래프
            * node_cpu_seconds_total: 각 모드에서 CPU 마다 얼마나 많은 시간을 소비했는지 나타내는 카운터로서, 레이블은 cpu 와 mode
            ![image](https://user-images.githubusercontent.com/41561652/113255394-c0df2800-9302-11eb-9cff-d0c99a751256.png)

            * [1m]: 1분동안의 값을 range vector형태로 가져옴
            * rate: 특정 시간동안의 range vector에서 값의 평균 변화량
            * irate: 특정 시간동안의 range vector에서 값의 변화량(시작과 끝점만 보고 구한 변화량)
            * avg without(cpu): cpu label은 뺀다 => 코어에 상관없이 생각 => 전체 CPU사용량 계산


            ## Memory Usage
            ![image](https://user-images.githubusercontent.com/41561652/113255435-cdfc1700-9302-11eb-808f-435de1f6d067.png)
            * node_memory_MemTotal_bytes: 
               * 머신의 실제 메모리 총량
            * node_memory_MemFree_bytes: 
               * 사용되지 않은 메모리의 총량
               * 이게 곧 여유 분의 총량이라는 의미는 아님!
            * node_memory_Cached_bytes: 
               * 케시로 사용되고 있는 메모리
            * node_memory_Buffers_bytes: 
               * 버퍼로 사용되고 있는 메모리


            ## Disk-Used
            ![image](https://user-images.githubusercontent.com/41561652/113255585-f71ca780-9302-11eb-9f55-ba2046d58ac1.png)



            ## Network Traffic
            ![image](https://user-images.githubusercontent.com/41561652/113255617-00a60f80-9303-11eb-80c7-97c75354e2d9.png)



4.  alert()
    
    1. prometheus 내부에 정의된 rule
         * ![image](https://user-images.githubusercontent.com/41561652/113257112-16b4cf80-9305-11eb-8e09-c0371889197d.png)

    2. alertmanager
         * ![image](https://user-images.githubusercontent.com/41561652/113257189-30561700-9305-11eb-87cd-eb0193a64859.png)

    3. slack
         * ![image](https://user-images.githubusercontent.com/41561652/113257230-44017d80-9305-11eb-9147-e97666884fc2.png)


    
5. Grafana Demo

    * DataSource 설정
    * 사이드 바 메뉴 간단 설명
    * DashBoard example: 
       * Node exporter full: http://localhost:3000/d/rYdddlPWk/node-exporter-full?orgId=1&refresh=1m
       * JVM(Micro meter): http://localhost:3000/d/y6AL2FlMk/jvm-micrometer?orgId=1&refresh=30s


# Reference

* https://prometheus.io/docs/introduction/overview/
* https://grafana.com/
* https://github.com/prometheus-community
* https://github.com/prometheus
