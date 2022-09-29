file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .cpp


add_executable(main ${srcs} ${hdrs}) #Создаем проект с именем main в него добавляются файлы из переменных ${srcs} , ${hdrs} и тд
target_include_directories(main PUBLIC ../LibImage)
target_link_libraries(main LibImage) #Подключаем к проекту с именем main статическую библиотеку с именем LibImage