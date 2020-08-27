import junit.framework.TestCase;

import org.intel.openvino.*;

import java.nio.file.Paths;

public class IETest extends TestCase {
    String modelXml;
    String modelBin;
    String device;

    public IETest() {
        try {
            System.loadLibrary(IECore.NATIVE_LIBRARY_NAME);
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Failed to load Inference Engine library\n" + e);
            System.exit(1);
        }

        modelXml =
                Paths.get(
                                System.getenv("MODELS_PATH"),
                                "models",
                                "test_model",
                                "test_model_fp32.xml")
                        .toString();
        modelBin =
                Paths.get(
                                System.getenv("MODELS_PATH"),
                                "models",
                                "test_model",
                                "test_model_fp32.bin")
                        .toString();
        device = "CPU";
    }
}
