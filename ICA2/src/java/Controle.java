
import java.io.IOException;
import javax.servlet.RequestDispatcher;
import modelo.Pessoa;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import modelo.PessoaDAO;

/**
 *
 * @author Rômulo F. Douro <rfdouro at gmail.com>
 */
@WebServlet(urlPatterns = {"/Controle"})
public class Controle extends HttpServlet {

    @Override
    protected void service(HttpServletRequest request,
            HttpServletResponse response)
            throws ServletException, IOException {
        String acao = request.getParameter("acao");
        if (acao != null) {
            if (acao.equals("cadastrar")) {
                if (request.getParameter("nome") != null
                        && !request.getParameter("nome").equals("")) {
                    Pessoa p = new Pessoa();
                    p.setNome(request.getParameter("nome"));
                    try {
                        new PessoaDAO().insere(p);
                        //response.sendRedirect("lista.jsp");
                        request.setAttribute("mensagem", "Registro incluído");
                        RequestDispatcher rd = request.getRequestDispatcher("lista.jsp");
                        rd.forward(request, response);
                        return;
                    } catch (ServletException ex) {
                        throw ex;
                    }
                }
            } else if (acao.equals("excluir")) {
                if (request.getParameter("id") != null
                        && !request.getParameter("id").equals("")) {
                    Pessoa p = new Pessoa();
                    p.setId(Long.parseLong(request.getParameter("id")));
                    try {
                        new PessoaDAO().excluir(p);
                        request.setAttribute("mensagem", "Registro excluído");
                        RequestDispatcher rd = request.getRequestDispatcher("lista.jsp");
                        rd.forward(request, response);
                        return;
                    } catch (Exception ex) {
                        throw ex;
                    }
                }
            } else if (acao.equals("visualizar")) {
                if (request.getParameter("id") != null
                        && !request.getParameter("id").equals("")) {
                    Pessoa p = new Pessoa();
                    try {
                        p = new PessoaDAO().seleciona(Long.parseLong(request.getParameter("id")));
                        request.setAttribute("pessoa", p);
                        RequestDispatcher rd = request.getRequestDispatcher("alterar.jsp");
                        rd.forward(request, response);
                        return;
                    } catch (Exception ex) {
                        throw ex;
                    }
                }
            } else if (acao.equals("alterar")) {
               if (request.getParameter("nome") != null
                        && !request.getParameter("nome").equals("")&& request.getParameter("id") != null && !request.getParameter("id").equals("")) {
                    Pessoa p = new Pessoa();
                    p.setNome(request.getParameter("nome"));
                    p.setId(Long.parseLong(request.getParameter("id")));
                    try {
                        new PessoaDAO().alterar(p);
                        //response.sendRedirect("lista.jsp");
                        request.setAttribute("mensagem", "Registro alterado com Sucesso");
                        RequestDispatcher rd = request.getRequestDispatcher("lista.jsp");
                        rd.forward(request, response);
                        return;
                    } catch (ServletException ex) {
                        throw ex;
                    }
                }  
            }
        }
    }
}
