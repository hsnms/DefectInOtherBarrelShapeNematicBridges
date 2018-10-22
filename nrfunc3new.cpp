#include <math.h>
#include <stdio.h>
#include "Header2new.h"
/*#define EPI 1.0e-7*/ 
#define Pi 3.141592653589793
void **nrfunc3new( double **f, double **u, int n,int *qq, int a,int b,double R0, double K, double H)
{
  double h,v1,v2,v4,v5,v6,v7,v8,v9,v;
	int i,j;
	h=1.0/(n-1); 	

	for(j=1;j<=(int)(n*H-H+1);j++)
		for(i=1;i<=(int)(n*R0-R0+1);i++)
			f[i][j]=0.0;

	// really new for(j=b+2;j<=(int)((n*H-H+1))/2;j++)
	 for(j=b+2;j<(int)((n*H-H+1))-b;j++)
	  { v=0.0;
	    // really new for (i=2;i<qq[j-1]-(n-1)/8;i++)
	     for (i=2;i<qq[j+1]-b;i++)
			  {
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
				        
			/*f[i][j]=pow(sin(u[i][j]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][j])*(v4+v5)/(2.0*h)-pow(sin(u[i][j]),2)*q[j]*(v1+v2)/(h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*pow(q[j],2)*pow((v1+v2)/(2.0*h),2);*/
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
				
		}
	}


	 /* for(j=(int)((n*H-H+1))/2+1;j<(int)((n*H-H+1))-(n-1)/8;j++)//for(j=b+2;j<(int)((n*H-H+1))-(n-1)/8;j++) for waist
	  { v=0.0;
	    for (i=2;i<qq[(int)((n*H-H+1))];i++)//(i=qq[j-1]-(n-1)/8;i<qq[j-1]-(n-1)/16;i++)*//*for (i=2;i<qq[j-1]-(n-1)/8;i++) for waist
			  {
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
		        
			
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
			
	        
	        	v=v+f[i][j]/((n-1)*(n-1));
			  }
			  // printf("j=%d\tqq[%d]=%d\tu[qq[%d]][%d]=%f\tv=%f\n",j,j,qq[j],j,j,u[qq[j]][j],v);			  }*/



	
		for(i=2;i<a-b;i++)
	{
		for (j=2;j<=1+b;j++)
		{
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
			        
			/*f[i][j]=pow(sin(u[i][j]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][j])*(v4+v5)/(2.0*h)-pow(sin(u[i][j]),2)*q[j]*(v1+v2)/(h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*pow(q[j],2)*pow((v1+v2)/(2.0*h),2);*/
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
				
		}
	}	

		
	        for(j=2;j<=1+b;j++)
		{
		  // really new for (i=b+a+1;i<qq[j]-(n-1)/8;i++)
		  	  for (i=b+a+1;i<qq[j+1];i++)
			{
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
			        
			/*f[i][j]=pow(sin(u[i][j]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][j])*(v4+v5)/(2.0*h)-pow(sin(u[i][j]),2)*q[j]*(v1+v2)/(h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*pow(q[j],2)*pow((v1+v2)/(2.0*h),2);*/
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
				
		}
	}

		/*****/
	        /*for(j=(int)(n*H-H+1)-b;j<(int)(n*H-H+1);j++)
		{
		  for (i=2;i<qq[(int)(n*H-H+1)-b]-b-b;i++)
			{
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
	        
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
				
		}
		}*/

		/*	for (i=2;i<=a-b-1;i++)
	{
			v1=u[i][2]-u[i][1];
		    v2=u[i][2]-u[i][1];
			v4=u[i+1][1]-u[i][1];
			v5=u[i][1]-u[i-1][1];
				
			j=1;
       
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
			

	}

	for (i=a+b+1;i<=qq[1]-1-(n-1)/8;i++)
	{
			v1=u[i][2]-u[i][1];
		    v2=u[i][2]-u[i][1];
			v4=u[i+1][1]-u[i][1];
			v5=u[i][1]-u[i-1][1];
				
			j=1;
			//f[i][1]=pow(sin(u[i][1]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][1])*(v4+v5)/(2.0*h)-pow(sin(u[i][1]),2)*q[j]*(v1+v2)/(h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*pow(q[j],2)*pow((v1+v2)/(2.0*h),2);
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
			

				}*/

		/*for (i=2;i<=qq[(int)(n*H-H+1)-b]-b-1-b;i++)
	{
			v1=u[i][(int)(n*H-H+1)]-u[i][(int)(n*H-H+1)-1];
		    v2=u[i][(int)(n*H-H+1)]-u[i][(int)(n*H-H+1)-1];
			v4=u[i+1][(int)(n*H-H+1)]-u[i][(int)(n*H-H+1)];
			v5=u[i][(int)(n*H-H+1)]-u[i-1][(int)(n*H-H+1)];
			 
			j=(int)(n*H-H+1);
        
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
			

				}*/
		/*	for (j=2;j<=(int)(n*H-H+1)-1;j++)
	{
		    v1=u[1][j+1]-u[1][j];
		    v2=u[1][j]-u[1][j-1];
			v4=u[2][j]-u[1][j];
			v5=u[2][j]-u[1][j];
				       
			i=1;
			//f[1][j]=sin(2.0*u[1][j])*(v4+v5)/(2.0*h)-pow(sin(u[1][j]),2)*q[j]*(v1+v2)/(h);
			f[i][j]=((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
			
				}*/

	/*for (j=2;j<=(int)(n*H-H+1)-b-1;j++)
	{
		    v1=u[(int)(n*R0-R0+1)][j+1]-u[(int)(n*R0-R0+1)][j];
		    v2=u[(int)(n*R0-R0+1)][j]-u[(int)(n*R0-R0+1)][j-1];
			v4=u[(int)(n*R0-R0+1)][j]-u[(int)(n*R0-R0+1)-1][j];
			v5=u[(int)(n*R0-R0+1)][j]-u[(int)(n*R0-R0+1)-1][j];
				        
			i=(int)(n*R0-R0+1);
        
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
			
				}*/

	/*	for (j=2;j<=b;j++)
	{
		    v1=u[a-b][j+1]-u[a-b][j];
		    v2=u[a-b][j]-u[a-b][j-1];
			v4=u[a-b][j]-u[a-b-1][j];
			v5=u[a-b][j]-u[a-b-1][j];
				        
			i=a-b;
		if (i==1)
		{
			f[i][j]=((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
		}
		else
		{
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
		}
		}*/

		/*	for (j=(int)(n*H-H+1)-b+1;j<=(int)(n*H-H+1)-1;j++)
	{
		    v1=u[(int)(n*R0-R0+1)-b][j+1]-u[(int)(n*R0-R0+1)-b][j];
		    v2=u[(int)(n*R0-R0+1)-b][j]-u[(int)(n*R0-R0+1)-b][j-1];
			v4=u[(int)(n*R0-R0+1)-b][j]-u[(int)(n*R0-R0+1)-b-1][j];
			v5=u[(int)(n*R0-R0+1)-b][j]-u[(int)(n*R0-R0+1)-b-1][j];
				        
			i=(int)(n*R0-R0+1)-b;
        
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
				}*/

		/*for (j=2;j<=b;j++)
	{
		    v1=u[a+b][j+1]-u[a+b][j];
		    v2=u[a+b][j]-u[a+b][j-1];
			v4=u[a+b+1][j]-u[a+b][j];
			v5=u[a+b+1][j]-u[a+b][j];
			        
			i=a+b;
			//f[i][j]=pow(sin(u[i][j]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][j])*(v4+v5)/(2.0*h)-pow(sin(u[i][j]),2)*q[j]*(v1+v2)/(h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*pow(q[j],2)*pow((v1+v2)/(2.0*h),2);
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
	}


		for (i=a-b+1;i<=a+b-1;i++)
	{
		    v1=u[i][b+2]-u[i][b+1];
		    v2=u[i][b+2]-u[i][b+1];
			v4=u[i+1][b+1]-u[i][b+1];
			v5=u[i][b+1]-u[i-1][b+1];
					        
			j=b+1;
			//f[i][j]=pow(sin(u[i][j]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][j])*(v4+v5)/(2.0*h)-pow(sin(u[i][j]),2)*q[j]*(v1+v2)/(h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*pow(q[j],2)*pow((v1+v2)/(2.0*h),2);
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
				}*/

		/*for (i=(int)(n*R0-R0+1)-b+1;i<=(int)(n*R0-R0+1)-1;i++)
	{
		    v1=u[i][(int)(n*H-H+1)-b]-u[i][(int)(n*H-H+1)-b-1];
		    v2=u[i][(int)(n*H-H+1)-b]-u[i][(int)(n*H-H+1)-b-1];
			v4=u[i+1][(int)(n*H-H+1)-b]-u[i][(int)(n*H-H+1)-b];
			v5=u[i][(int)(n*H-H+1)-b]-u[i-1][(int)(n*H-H+1)-b];
			        
			j=(int)(n*H-H+1)-b;
       
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
				}*/
		/* v1=u[1][2]-u[1][1];
		    v2=u[1][2]-u[1][1];
			v4=u[2][1]-u[1][1];
			v5=u[2][1]-u[1][1];
	        		       
			i=1;j=1;
			//f[1][j]=sin(2.0*u[1][j])*(v4+v5)/(2.0*h)-pow(sin(u[1][j]),2)*q[j]*(v1+v2)/(h);
			f[i][j]=((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);

			v1=u[1][(int)(n*H-H+1)]-u[1][(int)(n*H-H+1)-1];
		    v2=u[1][(int)(n*H-H+1)]-u[1][(int)(n*H-H+1)-1];
			v4=u[2][(int)(n*H-H+1)]-u[1][(int)(n*H-H+1)];
			v5=u[2][(int)(n*H-H+1)]-u[1][(int)(n*H-H+1)];
				       
			i=1;j=(int)(n*H-H+1);
			//f[1][j]=sin(2.0*u[1][j])*(v4+v5)/(2.0*h)-pow(sin(u[1][j]),2)*q[j]*(v1+v2)/(h);
			f[i][j]=((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
			
			/*v1=u[(int)(n*R0-R0+1)][2]-u[(int)(n*R0-R0+1)][1];
		    v2=u[(int)(n*R0-R0+1)][2]-u[(int)(n*R0-R0+1)][1];
			v4=u[(int)(n*R0-R0+1)][1]-u[(int)(n*R0-R0+1)-1][1];
			v5=u[(int)(n*R0-R0+1)][1]-u[(int)(n*R0-R0+1)-1][1];
				        
			i=(int)(n*R0-R0+1);j=1;
		f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
	
			/* v1=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-1];
		    v2=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-1];
			v4=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)-1][(int)(n*H-H+1)];
			v5=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)-1][(int)(n*H-H+1)];
				        
			i=(int)(n*R0-R0+1);j=(int)(n*H-H+1);
		f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
	
            
		/* v1=u[a-b][2]-u[a-b][1];
		    v2=u[a-b][2]-u[a-b][1];
			v4=u[a-b][1]-u[a-b-1][1];
			v5=u[a-b][1]-u[a-b-1][1];
	        
			i=a-b;j=1;
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
	
           
			v1=u[a+b][2]-u[a+b][1];
		    v2=u[a+b][2]-u[a+b][1];
			v4=u[a+b+1][1]-u[a+b][1];
			v5=u[a+b+1][1]-u[a+b][1];
				
			i=a+b;j=1;
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
			
			
			/*	v1=u[(int)(n*R0-R0+1)-b][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)-b][(int)(n*H-H+1)-1];
		    v2=u[(int)(n*R0-R0+1)-b][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)-b][(int)(n*H-H+1)-1];
			v4=u[(int)(n*R0-R0+1)-b][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)-b-1][(int)(n*H-H+1)];
			v5=u[(int)(n*R0-R0+1)-b][(int)(n*H-H+1)]-u[(int)(n*R0-R0+1)-b-1][(int)(n*H-H+1)];
				 
			i=(int)(n*R0-R0+1)-b;j=(int)(n*H-H+1);
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
			
			
			/*	v1=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-b]-u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-b-1];
		    v2=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-b]-u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-b-1];
			v4=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-b]-u[(int)(n*R0-R0+1)-1][(int)(n*H-H+1)-b];
			v5=u[(int)(n*R0-R0+1)][(int)(n*H-H+1)-b]-u[(int)(n*R0-R0+1)-1][(int)(n*H-H+1)-b];
			
			i=(int)(n*R0-R0+1);j=(int)(n*H-H+1)-b;
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
			
			/*i=a-b;j=b+1;
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
		  
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);
			
			i=a+b;j=b+1;
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
			  
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
			
			/*i=(int)(n*R0-R0+1)-b;j=(int)(n*H-H+1)-b;
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
			  
			f[i][j]=K*pow(sin(u[i][j]),2)/(h*(i-1))+((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(i-1))*pow(v4+v5,2)/(4.0*h)
				+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*(i-1)*pow((v1+v2),2)/(4.0*h)-((K-1.0)*sin(2.0*u[i][j])*(i-1))*(v1+v2)*(v4+v5)/(4.0*h)
				+(K*sin(2.0*u[i][j]))*(v4+v5)/(2.0*h)+K*(cos(2.0*u[i][j])-1.0)*(v1+v2)/(2.0*h);*/
			
	return 0;
}
