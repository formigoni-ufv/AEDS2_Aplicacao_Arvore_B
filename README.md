AEDS2_Aplicacao_Arvore_B
1.1
Se houver leitura no primeiro acesso, pagina é levada para a memoria	DISKREAD++
Se houver outra leitura, pagina está na memória							NULL

1.2
Se houver escrita após a leitura
	-Pagina e atualizada primeiro na memoria		NULL
	-Pagina e atualizada posteriormente no disco	DISKWRITE++
	
2.1
Se houver escrita no primeiro acesso
	- Pagina é levada pra memoria 		DISKREAD++
	- Pagina é atualizada na memoria	NULL
	- Pagina é atualizada no disco		DISKWRITE++
	
2.2
Se houver leituras após a escrita, pagina está na memória NULL