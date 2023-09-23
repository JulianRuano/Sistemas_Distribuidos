	do
	{
		printf("Ingrese el primer numero: ");
		scanf("%f", &operar_1_arg.a);
		printf("Ingrese el segundo numero: ");
		scanf("%f", &operar_1_arg.b);
		result_1 = operar_1(&operar_1_arg, clnt);
		if (result_1 == (nodo_multioperaciones *) NULL) {
		clnt_perror (clnt, "call failed");
		}
		else
		{
			printf("Estado: %s\n", result_1->estado);
			if (strcmp(result_1->estado, "Error") != 0)
			{
				printf("El resultado de la operacion es: %s\n", result_1->resultado);
			}		
			printf("Desea realizar otra operacion? (1=si, 0=no): ");
			scanf("%d", &op);		
		}
	} while (op == 0);