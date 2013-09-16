nclude<stdio.h>

int sem=0,slot[4]={0},wq=0;

int chkav(int f)
{
	if(f==1)
		{
			if(sem<4)
					return 1;
						return 0;
							}
								else
									{
										if(sem==0)
												return 0;
													return 1;
														}
														}


														void pe()
														{
															int chk = chkav(1);
																int i;
																	if(chk==1)
																		{
																				for(i=0;i<4;i++)
																						{
																									if(slot[i]==0)
																												{slot[i]=1;printf("\n Person enters in slot no. %d",i+1);break;}
																														}
																																sem++;
																																		return;	
																																			}
																																				wq++;
																																					printf("\n Slots full\nPerson enters in waiting queue at position %d",wq);
																																					}


																																					void px()
																																					{
																																						int chk = chkav(2);
																																							int s,i;
																																								if(chk==1)
																																									{
																																											printf("\n Enter Slot from which person is exiting....\n");
																																													scanf("%d",&s);
																																															if(s>0 && s<5)
																																																	{
																																																				if(slot[s-1]==1)
																																																							{
																																																										printf("\n Person exits from slot no. %d",s);
																																																													slot[s-1]=0;
																																																																sem--;
																																																																			}
																																																																						else
																																																																									{
																																																																												printf("\n Slot already empty...\n");
																																																																															}
																																																																																	}
																																																																																			if(wq>0)
																																																																																					{
																																																																																								printf("\n person from waiting queue occupies the slot no. %d",s);
																																																																																											wq--;
																																																																																														for(i=0;i<4;i++)
																																																																																																	{
																																																																																																					if(slot[i]==0)
																																																																																																									{slot[i]=1;break;}
																																																																																																												}
																																																																																																															sem++;
																																																																																																																	}
																																																																																																																			return;
																																																																																																																				}
																																																																																																																					printf("\n All slots are empty....no one exits\n");
																																																																																																																					}





																																																																																																																					int main()
																																																																																																																					{
																																																																																																																						int ch,i;
																																																																																																																							printf("\n**********BATHROOM PROBLEM**********\n\n");
																																																																																																																								do
																																																																																																																									{	
																																																																																																																										printf("\n OPTIONS\n");
																																																																																																																											printf("1. Person enters\n2. Person exits\n3. Check Slots Status\n4. Close\n\n");
																																																																																																																												scanf("%d",&ch);
																																																																																																																													switch(ch)
																																																																																																																														{
																																																																																																																																case 1:pe();break;
																																																																																																																																		case 2:px();break;
																																																																																																																																				case 3:for(i=0;i<4;i++){slot[i]==0?printf("\tempty"):printf("\toccupied");}break;
																																																																																																																																						case 4:return;
																																																																																																																																								default:printf("\n Invalid Selection...\n");
																																																																																																																																									}
																																																																																																																																										}while(1);
																																																																																																																																										return 0;
																																																																																																																																										}

