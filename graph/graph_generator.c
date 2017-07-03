#include "graph_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include "../statistic.h"

void GRAPH_DATA_RESET(){
	FILE* html;

	html = fopen("graph/graph_data.html", "w");
	fclose(html);
}

void GRAPH_ADDLINE(int reg_counter){
	FILE* html;

	html = fopen("graph/graph_data.html", "a");
	fprintf(html, " ['%d',  %d, %d, %d],\n", reg_counter, STATS_SCAN('r'), STATS_SCAN('w'), STATS_SCAN('c'));
	fclose(html);
}

void GRAPH_GEN(){
	FILE* graph;
	FILE* data;
	int i, reg[20], reads[20], writes[20], comparisons[20];

	data =	fopen("graph/graph_data.html", "r");
	for(i=0; i<20; i++){
		fscanf(data, " ['%d',  %d, %d, %d],\n", &reg[i], &reads[i], &writes[i], &comparisons[i]);
	}
	fclose(data);

	graph = fopen("graph/graph.html", "w");

	fprintf(graph, "<html>\n");
	fprintf(graph, "  <head>\n");
	fprintf(graph, "    <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n");
	fprintf(graph, "    <script type=\"text/javascript\">\n");
	fprintf(graph, "      google.charts.load('current', {'packages':['corechart']});\n");
	fprintf(graph, "      google.charts.setOnLoadCallback(drawChart);\n");
	fprintf(graph, "\n");
	fprintf(graph, "      function drawChart() {\n");
	fprintf(graph, "        var data = google.visualization.arrayToDataTable([\n");
	fprintf(graph, "          ['Registros', 'Leituras', 'Escritas', 'Comparacoes'],\n");
	for(i=0; i<19; i++){
		fprintf(graph, "          ['%d',  %d, %d, %d],\n", reg[i], reads[i], writes[i], comparisons[i]);
	}
	fprintf(graph, "          ['%d',  %d, %d, %d]\n", reg[19], reads[19], writes[19], comparisons[19]);
	fprintf(graph, "        ]);\n");
	fprintf(graph, "        var options = {\n");
	fprintf(graph, "          curveType: 'function',\n");
	fprintf(graph, "          legend: { position: 'bottom' }\n");
	fprintf(graph, "        };\n");
	fprintf(graph, "\n");
	fprintf(graph, "        var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));\n");
	fprintf(graph, "\n");
	fprintf(graph, "        chart.draw(data, options);\n");
	fprintf(graph, "      }\n");
	fprintf(graph, "    </script>\n");
	fprintf(graph, "  </head>\n");
	fprintf(graph, "  <body>\n");
	fprintf(graph, "    <div id=\"curve_chart\" style=\"width: 2400px; height: 800px\"></div>\n");
	fprintf(graph, "  </body>\n");
	fprintf(graph, "</html>\n");

	fclose(graph);
}