/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:20:43 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/20 19:09:42 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include <string.h>
#include <unistd.h>
//#include <curl/curl.h>

const int	n_required_fields_kafka = 5;
char	*required_fields[] = {"endpoint", "method", "request_body", "response_body", NULL};
const int	n_required_fields = 4;
char	*required_fields_kafka[] = {"integration_type", "bootstrap_servers", "topic", "group_id", "auto_offset_reset", NULL};

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

void	ft_get_input(const char *prompt, char *buf, size_t buflen)
{
	size_t	len;

	printf("%s", prompt);
	fflush(stdout);
	if (fgets(buf, buflen, stdin))
	{
		len = ft_strlen(buf);
		if (len > 0 && buf[len - 1] == '\n')
			buf[len - 1] = '\0';
	}
}

void	ft_check_and_fill_fields(cJSON *desc_json, int code)
{
	int	i;
	int	n;
	char	**s = NULL;

	i = 0;
	n = 0;
	if (code == 5)
	{
		n = n_required_fields_kafka;
		s = required_fields_kafka;
	}
	else if (code == 4)
	{
		s = required_fields;
		n = n_required_fields;
	}
	printf("\nNecessary field checking...\n");
	sleep(1);
	printf("...");
	sleep(1);
	while (i < n)
	{
		if (!cJSON_GetObjectItem(desc_json, s[i]))
		{
			char	tmp[256];
			printf("\nField '%s' is required, but missing.\n", s[i]);
			ft_get_input("Please, provide value: ", tmp, sizeof(tmp));
			cJSON_AddStringToObject(desc_json, s[i], tmp);
		}
		i++;
	}
	printf("Creating a prompt...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
}

void	ft_build_prompt(cJSON *desc_json, char *prompt, size_t prompt_len, int code)
{
	if (code == 5)
	{
		snprintf(prompt, prompt_len,
		"Generate a valid JSON for the Kafka_Consumer integration scenario:\n"
		"Integration_type:%s\nBootstrap_servers:%s\nTopic:%s\nGroup_id:%s\nAuto_offset_reset:%s\n",
		cJSON_GetObjectItem(desc_json, "integration_type")->valuestring,
		cJSON_GetObjectItem(desc_json, "bootstrap_servers")->valuestring,
		cJSON_GetObjectItem(desc_json, "topic")->valuestring,
		cJSON_GetObjectItem(desc_json, "group_id")->valuestring,
		cJSON_GetObjectItem(desc_json, "auto_offset_reset")->valuestring);
	}
	else if (code == 4)
	{
		snprintf(prompt, prompt_len,
		"Generate a valid JSON for the REST API integration scenario:\n"
		"Endpoint:%s\nMethod:%s\nRequest Body:%s\nResponse Body:%s\n",
		cJSON_GetObjectItem(desc_json, "endpoint")->valuestring,
		cJSON_GetObjectItem(desc_json, "method")->valuestring,
		cJSON_GetObjectItem(desc_json, "request_body")->valuestring,
		cJSON_GetObjectItem(desc_json, "response_body")->valuestring);
	}
}

int	ft_send_to_ai(const char *prompt, char **response)
{
	(void)prompt;
	(void)response;
	//curl library;
	return (0);
}

char	*ft_kafka_consumer(void)
{
	char *desc = "\"integration_type\":\"Kafka_Consumer\"";
	return (desc);
}

int	main(void)
{
	char	input[1024];
	char	prompt[2048];
	char	*ai_response;
	int	code;
	cJSON	*desc_json = NULL;

	printf("Please, describe your business process and integration scenario:\n");
	fgets(input, sizeof(input), stdin);
	code = 4;
	if (!strncmp(input, "Kafka_Consumer", 14))
	{
		desc_json = cJSON_Parse(ft_kafka_consumer());
		code = 5;
	}
	else
	{
		printf("Let's generate a JSON for REST API integration scenario...\n");
		desc_json = cJSON_Parse(input);
	}
	if (!desc_json)
	{
		printf("Invalid JSON. Exiting.\n");
		exit (EXIT_FAILURE);
	}
	ft_check_and_fill_fields(desc_json, code);
	ft_build_prompt(desc_json, prompt, sizeof(prompt), code);
	printf("\nPROMPT:\n%s\nRequest to AI...(TODO)\n", prompt);
	sleep(1);
	ai_response = NULL;
	if (ft_send_to_ai(prompt, &ai_response) != 0)
	{
		printf("Failed to get response from AI.\n");
		cJSON_Delete(desc_json);
		exit(EXIT_FAILURE);
	}
}
