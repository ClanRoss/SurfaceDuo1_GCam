/* Generated test code to dump a table of data for external validation
 * of the noise model parameters.
 */
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 50; sens <= 100; sens += 100) {
            double o = compute_noise_model_entry_O(plane, sens);
            double s = compute_noise_model_entry_S(plane, sens);
            printf("%d,%d,%lf,%lf\n", plane, sens, o, s);
        }
    }
    return 0;
}

/* Generated functions to map a given sensitivity to the O and S noise
 * model parameters in the DNG noise model. The planes are in
 * R, Gr, Gb, B order.
 */
double compute_noise_model_entry_S(int plane, int sens) {
    static double noise_model_A[] = { 3.158947957454044e-06,3.0213071125783504e-06,3.0041724185451916e-06,3.147703590208173e-06 };
    static double noise_model_B[] = { -5.551394517963423e-06,1.4380684212400637e-05,1.529844740096727e-05,5.435857330099242e-06 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 5.573039412139685e-11,5.857693669211056e-11,6.365255239600544e-11,5.6388715259173276e-11 };
    static double noise_model_D[] = { 1.2039713940469865e-07,-3.460095694370271e-07,-3.5374756941908683e-07,-2.9706445574643345e-08 };
    double digital_gain = (sens / 800.0) < 1.0 ? 1.0 : (sens / 800.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}
