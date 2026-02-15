#include <stdio.h>
#include <math.h>
void calculareaunghiurilor( const double *v, double *u) {
    double i1=0, i2=0, i3=0;
    i1=(v[0]*v[0]+v[1]*v[1]-v[2]*v[2])/(2*v[0]*v[1]);
    i2=(v[2]*v[2]+v[1]*v[1]-v[0]*v[0])/(2*v[2]*v[1]);
    i3=(v[0]*v[0]+v[2]*v[2]-v[1]*v[1])/(2*v[0]*v[2]);
    u[0]=acos(i1);
    u[1]=acos(i2);
    u[2]=acos(i3);
}


int main () {
    int i=0;
    double u1=0, u2=0, u3=0;
    double u[3]={u1,u2,u3};
    double v[3];
    for (i=0; i<3; i++) {
        scanf("%lf", &v[i]);
    }

    calculareaunghiurilor(v,u);
    u1=u[0];
    u2=u[1];
    u3=u[2];
    printf("%.3lf %.3lf %.3lf",(u1*180)/M_PI,(u2*180)/M_PI,(u3*180)/M_PI);

}